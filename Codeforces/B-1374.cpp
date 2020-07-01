#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/28
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        ll count = 0;
        ll n;
        cin >> n;
        bool possible = true;
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        while (true)
        {
            if (n == 1) break;
            if (n % 6 == 0)
            {
                n /= 6;
                ++count;
            }
            else if (n % 3 == 0)
            {
                n *= 2;
                ++count;
            }
            else
            {
                possible = false;
                break;
            }
        }
        if (possible) cout << count << '\n';
        else cout << -1 << '\n';
    }
}
