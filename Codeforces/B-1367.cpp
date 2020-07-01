#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
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
        int n;
        cin >> n;
        vector<int> a(n);
        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i] = a[i] % 2;
            //cout << a[i] << endl;
        }
        ll count = 0;
        int zero = 1, one = 0;
        while (one < n)
        {
            if (a[one] != 0)
            {
                while (a[zero] != 0 && zero < n) zero += 2;
                if (zero >= n) break;
                swap(a[one], a[zero]);
                ++count;
            }
            one += 2;
        }
        for (int i = 0; i < n; i++)
        {
            //cout << a[i] << '\n';
            if (a[i] != i % 2)
            {
                cout << "-1" << '\n';
                possible = false;
                break;
            }
        }
        a.clear();
        if (!possible) continue;
        cout << count << '\n';
        
    }
}
