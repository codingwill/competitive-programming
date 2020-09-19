#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 998244353;

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
	//ios_base::sync_with_stdio(false);
    //.tie(NULL);
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
    ll n = 0;
    ll awal, tujuan;
    cin >> awal >> tujuan;
    ll m;
    cin >> m;
    string s;
    getline(cin, s);
    int len = s.length();
    vector<vector<int>> a(1);
    for (auto i = 0; i < len; i += 2)
    {
        if (input == '1')
        {
            a[0].push_back(i/2);
        }
        n++;
    }
    for (int i = 1; i < n; ++i)
    {
        a.push_back(vector<int>());
        for (int j = 0; j < n; ++j)
        {
            int input;
            cin >> input;
            if (input == 1)
            {
                a[i].push_back(j);
            }
        }
    }

}