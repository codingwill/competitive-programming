#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
*/

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.length() == 2)
        {
            cout << s << '\n';
            continue;
        }
        int i = 0;
        while (i < s.length()-1)
        {
            cout << s[i];
            i += 2;
        }
        cout << s[s.length()-1];
        cout << '\n';
    }
}