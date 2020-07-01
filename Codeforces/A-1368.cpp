#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/18
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
        ll a, b, n;
        cin >> a >> b >> n;
        ll ans = 0;
        while (!(a > n || b > n))
        {
            if (a < b)
            {
                a += b;
            }
            else
            {
                b += a;
            }
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}