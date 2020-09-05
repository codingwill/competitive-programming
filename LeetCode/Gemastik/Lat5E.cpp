#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/25
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

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (m == 1) cout << m + 1 << '\n';
    else if (m == n) cout << m - 1 << '\n';
    else if (abs(m-1) >= abs(n-m))
    {
        cout << m - 1 << '\n';
    }
    else cout << m + 1 << '\n';
    
}

/*

*/