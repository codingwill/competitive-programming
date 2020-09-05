#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/31
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
    ll n;
    cin >> n;
    vector<ll> a;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i)
    {
        ll l, r;
        cin >> l >> r;
        if (m.find(l) != m.end())
        {
            if (m[l] < r) m[l] = r;
        }
        else m[l] = r;
    }
    ll kiri, kanan;
    ll ans = 0;
    //binary search
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        //cout << it->first << ' ' << it->second << '\n';
        if (it == m.begin())
        {
            kiri = it->first;
            kanan = it->second;
        }
        else
        {
            if (it->first <= kanan && it->second > kanan)
            {
                kanan = it->second;
            }
            else if (it->first > kanan)
            {
                ans += (kanan - kiri + 1) * (kiri + kanan) / 2;
                kiri = it->first;
                kanan =it->second;
            }
        }
    }
    ans += (kanan - kiri + 1) * (kiri + kanan) / 2;
    cout << ans << '\n';

}
/*

*/