#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
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

bool sortPairFirst(pair<int, bool> &a, pair<int, bool> &b)
{
    if (a.first == b.first) return a.second > b.second;
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+n);
    for (int i = 0; i < 2*n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool can = true;
    for (int i = 0; i < 2*n; i += 2)
    {
        if (a[i+1] - a[i] > k) can = false;
    }
    if (can) cout << "Ya\n";
    else cout << "Tidak\n";
    //cout << a[1] << ' ' << a[0] << '\n';
}
/*

*/