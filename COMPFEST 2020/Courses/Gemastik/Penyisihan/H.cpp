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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> pref(n, vector<ll>(m, 0));
    for (int i = 0 ; i < n; ++i)
    {
        ll sum = 0;
        for (int j = 0 ; j < m; ++j)
        {
            cin >> a[i][j];
            sum += a[i][j];
            pref[i][j] = sum;
            if (i > 0)
            {
                pref[i][j] += pref[i-1][j];
            }
        }
    }
    /*
    for (int i = 0 ; i < n; ++i)
    {
        ll sum = 0;
        for (int j = 0 ; j < m; ++j)
        {
            cout << pref[i][j] << ' ';
        }
        cout << endl;
    }
    */

    for (int i = 0;  i < q; ++i)
    {
        ll ans = 0;
        ll x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        x1--; x2--; y1--; y2--;
        ans = pref[y2][x2];
        if (x1 > 0) ans -= pref[y2][x1-1];
        if (y1 > 0) ans -= pref[y1-1][x2];
        if (x1 > 0 && y1 > 0) ans += pref[y1-1][x1-1];
        cout << ans << '\n';
    }
}