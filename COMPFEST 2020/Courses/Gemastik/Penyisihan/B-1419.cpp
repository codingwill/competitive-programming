#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 


void solve()
{
    vector<ll> baris;
    for (int i = 1; i < 32; ++i)
    {
        baris.push_back(fastpow(2, i) - 1);
    }
    vector<ll> countCell;
    for (int i = 0; i < baris.size(); ++i)
    {
        countCell.push_back(baris[i] * (baris[i] + 1) / 2);
    }
    //for (auto n : countCell) cout << n << ' ';
    //cout << '\n';
    int t;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        int i = 0;
        ll sum = 0;
        while (sum <= x || sum < 0)
        {
            sum += countCell[i];
            i++;
        }
        cout << i - 1 << '\n';
    }
}

/*
1 3 7 15 31 63
1 6 

1 3 6 10 15 21

1000000000000000000
2305843008139952128

7 1 6 2 4 3 5
*/