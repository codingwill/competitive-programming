#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= MOD;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
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
    ll n;
    cin >> n;
    ll ans = (2 * (n-1) * n / 2) % MOD ;
    //cout << ans << '\n';
    ans = (ans) * (fastpow((ll)10, n-2LL)) % MOD ;
    //cout << (fastpow(ll(10), n-2) % MOD) << '\n';
    cout << ans << '\n';
}

/*
2511445
93131637
(n-1) * (n) / 2
3
0 () 9 = 10 cara
9 () 0 = 10 cara
9 0 () = 9 cara
0 9 () = 9 cara
() 9 0 = 8 cara
() 0 9 = 8 cara
9 9

0 - - 9     100
0 - 9 -      90
0 9 - -  
- 0 - 9
- 0 9 -  
- - 0 9  


0 () 9 10
0 9 ()  9
() 0 9  9
9 () 0  10
9 0 ()  8
() 9 0  8

*/