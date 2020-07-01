#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;


int a[100][7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s[n][7];
    for  (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> s[i][j];
            for (int k = 0; k < s[i][j].length(); k++)
            {
                if (s[i][j][k] == '#')
                {
                    a[i][j]++;
                }
            }
        }
    }
    for  (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << a[i][j];
            
        }
        cout << '\n';
    }
}