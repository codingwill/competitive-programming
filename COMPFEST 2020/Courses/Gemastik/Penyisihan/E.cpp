#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 100000037;

void solve();

ll fastpow(ll x, ll y, ll n = MOD) 
{
    x %= MOD;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = ((ans % MOD) * (x % MOD)) % MOD;
        x = ((x % MOD) * (x % MOD)) % MOD;
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
    //cin.tie(NULL);
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
    ll n;
    cin >> n;
    ll ans = 1;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    
    for (int i = n-1; i >= 0; --i)
    {
        if (i == n-1)
        {
            ans = fastpow(a[i], 1) % MOD;
        }
        else
        {
            ans = fastpow(a[i], ans) % MOD;
        }
    }
    cout << ans;
}