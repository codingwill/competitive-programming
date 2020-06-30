#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll x, y;
        if (a > c)
        {
            x = -1;
            y = 1;
        }
        else if (a == c)
        {
            if (b == 1) y = -1;
            else y = b;
            x = -1;
        }
        else
        {
            x = 1;
            if (a * b <= c) 
                y = -1;
            else
            {
                y = b;
            }
        }
        cout << x << ' ' << y << '\n';
    }
}

/*
2 3 5
2 4 6
5 5 5

3 1 3
*/