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
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> count;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        int k = 0;
        //cout << 't' << '\n';
        bool firstDone = false;
        //tahap1 (0, ..., n)
        while (true)
        {
            for (int i = 0; i <= 1000; ++i)
            {
                if (count[i] < 1)
                {
                    if (i )
                    {
                        firstDone = true;
                        break;
                    }
                }
            }
            if (firstDone) break;
        }

        //tahapDua (n+1, ..., 2*n)
        for (int j = 0; j < n; ++j)
        {
            for (int i = 0; i <= 1000; ++i)
            {
                if (count[i] < 1)
                {
                    a[i-1] = i;
                }
            }
        }
        for (int n : a)
        {
            cout << n << ' ';
        }
        cout << '\n';
        a.clear();
    }
}

/*

2 0 1 1 2 4 4 2 0
2 0 1 3 2 4 4 2 0
2 0 1 3 2 5 4 2 0
2 0 1 3 2 5 6 2 0
2 0 1 3 4 5 6 2 0
2 0 1 3 4 5 6 7 0
2 0 1 3 4 5 6 7 8
2 0 1 3 4 5 6 7 9
2 0 1 3 4 5 6 8 9


0 7 3 1 3 7 7
0 7 2 1 3 7 7
0 7 2 1 4 7 7
0 7 2 3 4 7 7
0 1 2 3 4 7 7
0 1 2 3 4 5 7
0 1 2 3 4 5 6

2 1 0
2 1 3
0 1 3

*/