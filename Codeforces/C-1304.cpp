#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/01
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll q;
    cin >> q;
    cin.ignore();
    while (q--)
    {
        ll n, m;
        cin >> n >> m;
        ll prevTime = 0;
        ll prevLow = m, prevHigh = m;
        ll prevRange = 0;
        bool possible = true;
        for (ll i = 0; i < n; ++i)
        {
            ll t, l, h;
            cin >> t >> l >> h;
            prevRange = t - prevTime;
            if (prevLow - prevRange > h || prevHigh + prevRange < l)
            {
                possible = false;
            }
            prevLow = max(l, prevLow - prevRange);
            prevHigh = min(h, prevHigh + prevRange);
            
            prevTime = t;
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";
    }
}