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
    vector<ll> a(n);
    ll total = 0;
    map<ll, ll> count;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        total += a[i];
        count[a[i]]++;
    }
    ll divisor = 1;
    for(auto n : count)
    {
        if (n.second > 1) divisor *= fact(n.second) % MOD;
    }
    if (divisor == 0) divisor = 1;
    ll ans = 1;
    ans = ans * Combin(total, a[0]);
    ll used = 0;
    if (count.size() == 1 && count.begin()->first == 1)
    {
        cout << 1 << '\n';
    }    
    else
    {
        for (int i = 1; i < n-1; ++i)
        {
            used += a[i-1];
            ans = (ans * Combin(total - used, a[i])) % MOD;
        }
        cout << ans / divisor << '\n';
    }
    
    
}
/*
100 25
19

9 2
1 2

A B C (D E F)
A B D (C E F)
A B E (C D F)
A B F (C D E)

*/
