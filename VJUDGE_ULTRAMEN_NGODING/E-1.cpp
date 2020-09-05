#include <bits/stdc++.h>

/*
by: wkwkwill
date: 2020/08/05
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
        int x, y, z;
        cin >> x >> y >> z;
        int cnt = 0;
        if (max(x, max(y, z)) == x) cnt++;
        if (max(x, max(y, z)) == y) cnt++;
        if (max(x, max(y, z)) == z) cnt++;
        if (cnt == 1)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            cout << max(x, max(y, z)) << ' ' << min(x, min(y, z)) << ' ' << min(x, min(y, z)) << '\n';
        }
    }
}