#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/16
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

ll greedy(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2)
{
    ll ans = 0;
    ll temp = -1;
    temp = min(z1, y2);
    ans += temp * 2;
    z1 -= temp;
    y2 -= temp;
    temp = min(x1, z2);
    z1 -= temp;
    z2 -= temp;
    temp = min(y1, z2);
    ans -= temp * 2;
    y1 -= temp;
    z2 -= temp;
    return ans;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        ll ans = 0, temp = 0;
        temp = min(z1, y2);
        ans += temp * 2;
        z1 -= temp;
        y2 -= temp;
        temp = min(z1, z2);
        z1 -= temp;
        z2 -= temp;
        if (y1 > x2 + y2)
        {
            ans -= (y1 - (x2 + y2)) * 2;
        }
        cout << ans << '\n';
    }
}

/*
0 0 1
0 1 0

1 1 1
1 1 1
2 1 0
1 0 2

2 2 1 0 0
2 2 2 2 1

2 2 1 0 0
1 2 2 2 2
2 0 -2 0 0


*/