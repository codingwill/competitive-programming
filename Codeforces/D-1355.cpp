#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a[9][9];
        string s;
        for (int i = 0; i < 9; i++)
        {
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                a[i][j] = s[j] - '0';
            }
        }
        //box 1
        a[0][0] = ((a[0][0] + 3) % 9) + 1;
        a[1][8] = ((a[1][8] + 3) % 9) + 1;
        a[8][7] = ((a[8][7] + 3) % 9) + 1;
        a[7][1] = ((a[7][1] + 3) % 9) + 1;
        a[2][3] = ((a[2][3] + 3) % 9) + 1;
        a[3][6] = ((a[3][6] + 3) % 9) + 1;
        a[5][5] = ((a[5][5] + 3) % 9) + 1;
        a[4][2] = ((a[4][2] + 3) % 9) + 1;
        a[6][4] = ((a[6][4] + 3) % 9) + 1;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    

    return 0;
}
/*
4 2 4 1 4 3 4

WRONG TEST
1
4
1 1 1 3
[1]

1
5
2 1 5 4 3
[0]
*/