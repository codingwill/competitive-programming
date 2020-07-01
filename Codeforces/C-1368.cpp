#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/18
*/
using namespace std;
using ll = long long int;

string ans = "codeforce", s = "s";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << 500 << '\n';
    for (int i = 0; i < 126; ++i)
    {
        for (int j = 0; j < 126; ++j)
        {
            if (i == 0 || i == 125 || j == 0 || j == 125)
            {
                cout << i << ' ' << j << '\n';
            }
        }
    }
}