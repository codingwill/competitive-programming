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
        ll x, y, n;
        cin >> x >> y >> n;
        if (n % x >= y) cout << n - (abs(y - (n % x))) << '\n';
        else cout << n + (abs(y - (n % x))) - x << '\n';
    }
}