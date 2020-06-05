#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/05/31
*/
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll c = max(a, b) / min(a, b);
        ll count = 0;
        if (max(a, b) % min(a, b) != 0)
        {
            cout << "-1" << '\n';
            continue;
        }
        if (a == b)
        {
            cout << "0" << '\n';
            continue;
        }
        bool can = false;
        while (c != 1)
        {
            can = false;
            if (c % 8 == 0)
            {
                c /= 8;
                can = true;
            }
            else if (c % 4 == 0)
            {
                c /= 4;
                can = true;
            }
            else if (c % 2 == 0)
            {
                c /= 2;
                can = true;
            }
            if (!can)
            {
                break;
            }
            count++;
        }
        if (can) cout << count << '\n';
        else cout << "-1" << '\n';
    }
}
/*
6 18

*/