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
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        ll n, r, ans;
        cin >> n >> r;
        if (n <= r) cout << ((n * (n-1) / 2)) + 1 << '\n';
        else cout << ((r+1) * r / 2) << '\n';
    }
}