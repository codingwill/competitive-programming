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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), dp(n);
        ll maks = -1, iMaks;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            maks = max(maks, a[i]);
        }
        ll ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] < a[i-1]) ans += a[i-1] - a[i];
        }
        cout << ans << '\n';
    }
}


/*
6
2 9 4 3 6 8 5
+5
2 9 9 8 11 13 10
+1
2 9 9 9 12 14 11

5
3 1 3 1 3
3 3 5 3 5 -> 2

5
1 3 7 2 5
0 0 0 5 2 -> maksnya = 5

5
1 3 5 7 9 -> 0

5
5 4 3 2 1
0 1 2 3 4 -> 4

5
5 4 5 2 1
0 1 0 3 4 -> 1 + 4
5 

5
1 2 3 5 3
4 3 2 0 2
*/

/*
        for (int i = 0; i < n; ++i)
        {
            dp[i] = maks - a[i];
        }
        ll maksDP= 0;
        ll ans = 0;
        ll nol = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] != 0)
            {
                maksDP = max(maksDP, dp[i]);
            }
            else
            {
                if (i != 0 && nol > 0)
                {
                    ans += maksDP;
                }
                maksDP = 0;
                nol++;
            }
        }
        if (nol > 0) ans += maksDP;
        cout << ans << '\n';
        */