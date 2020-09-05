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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                //cout << n-1 << ' ' << m-1 << '\n';
                if ((i == 0 || i == n-1) && (j == 0 || j == m-1))
                {
                    if (a[i][j] > 2) possible = false;
                }
                else if ((i == 0 || i == n-1) && (j > 0 && j < m-1))
                {
                    
                    if (a[i][j] > 3) possible = false;
                }
                else if ((j == 0 || j == m-1) && (i > 0 && i < n-1))
                {
                    if (a[i][j] > 3) possible = false;
                }
                else
                {
                    if (a[i][j] > 4) possible = false;
                }
                
            }
        }
        //cout << a[1][1] << '\n';
        if (!possible) cout << "NO" << '\n';
        else
        {
            cout << "YES" << '\n';
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if ((i == 0 || i == n-1) && (j == 0 || j == m-1))
                    {
                        cout << 2;
                    }
                    else if ((i == 0 || i == n-1) && (j > 0 && j < m-1))
                    {
                        cout << 3;
                    }
                    else if ((j == 0 || j == m-1) && (i > 0 && i < n-1))
                    {
                        cout << 3;
                    }
                    else cout << 4;
                    if (j < m-1) cout << ' ';
                }
                cout << '\n';
            }
        }
        
    }
}

/*
0 1 0 0
0 2 2 1
0 0 0 0
0 0 0 0

*/