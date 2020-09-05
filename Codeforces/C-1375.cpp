#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/04
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
    
    int neg = 0;
    int pos = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        if (a[0] < a[n-1])
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
        
    }
}
/*
5 1 2 3 6 7 4

2 7 6 5 4 3 1 9 8 bisa
6 3 5 1 2 4 7

2 4 6 1 3 5
2 4 1 6 3 5
2 1 6 3 5
2 1 3 5
2 1 5
2 5

        10 2 6 5 1 3 7 4 8 12 9 11
        10 2 - - 1 - - - - - - 11
        10 2 11
        10 11
        11
        2 5 4 3 1
        2 4 3 1
        2 3 1
        2 1
        no

        2 3 4 1 5

        7 2 5 4 6 3 1 8
        7 2 4 6 3 1 8
        7 2 6 3 1 8
        7 2 3 1 8
        7 2 1 8
        7 2 8
        7
        */