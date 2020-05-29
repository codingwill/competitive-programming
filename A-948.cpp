#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std
//AUTHOR'S NAME
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    char a[r][c];
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == '.') a[i][j] = 'D';
        }
    }
    bool can = true;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (i > 0)
            {
                if (a[i][j] == 'S' && a[i-1][j] == 'W')
                {
                    can = false;
                }
            }
            if (i < r-1)
            {
                if (a[i][j] == 'S' && a[i+1][j] == 'W')
                {
                    can = false;
                }
            }
            if (j > 0)
            {
                if (a[i][j] == 'S' && a[i][j-1] == 'W')
                {
                    can = false;
                }
            }
            if (j < c-1)
            {
                if (a[i][j] == 'S' && a[i][j+1] == 'W')
                {
                    can = false;
                }
            }
            if (!can) break;
        }
        if (!can) break;
    }
    if (can)
    {
        cout << "Yes" << '\n';
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    else puts("No");

}