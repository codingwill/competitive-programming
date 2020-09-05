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
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (j == i) continue;
            for (int k = 0; k < 4; ++k)
            {
                if (k == j || k == i) continue;
                
                int count = 0;
                if (a[i] + a[j] > a[k]) count++;
                if (a[i] + a[k] > a[j]) count++;
                if (a[j] + a[k] > a[i]) count++;
                if (count == 3)
                {
                    cout << "TRIANGLE" << '\n';
                    return;
                }
                if (a[i] + a[j] == a[k]) ans++;
            }
        }
    }
    //cout << ans << '\n';
    if (ans == 0) cout << "IMPOSSIBLE" << '\n';
    else cout << "SEGMENT" << '\n';
}

/*

*/