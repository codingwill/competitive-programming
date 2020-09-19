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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> used(n, false);
    int i = 0;
    int quiz = n-1;
    while (quiz--)
    {
        int x, y;
        cout << "? " << i+1 << " " << i+2 << '\n';
        cout.flush();
        cin >> x;
        cout << "? " << i+2 << " " << i+1 << '\n';
        cout.flush();
        cin >> y;
        if (x > y)
        {
            a[i] = x;
            used[i] = true; 
        }
        else
        {
            a[i+1] = y;
            used[i+1] = true;
        }
        i++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!used[i]) a[i] = n;
    }
    cout << "! ";
    for (int n : a) cout << n << ' ';
    cout.flush();
}
/*
3 6 1 4 2 8 5 7
1 2
3
2 1
0
2 3
0
3 2
1
3 4
1
4 3
0
4 5
0
5 4
2
5 6
2
6 5
0
6 7
3
7 6
5
7 8
5
8 7
2

3 0 1 0 2 8 5 7

1 3 2
*/