#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
*/
using namespace std;
using ll = long long int;

int main()
{
    string s;
    cin >> s;
    vector<int> index(s.length(), 0);
    if (s.length() <= 2)
    {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < s.length()-3; ++i)
    {
        if (s[i] == 'A' && s[i+1] == 'B')
        {
            if (i == 0) index[i+2] = 1;
            else index[i+2] = index[i+1] + 1;
        }
        else
        {
            index[i+2] = index[i+1];
        }
    }
    for (int i = 0; i < s.length()-1; ++i)
    {
        if (s[i] == 'B' && s[i+1] == 'A')
        {
            if (index[i] >= 1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    index.clear();
    for (int i = 0; i < s.length()-3; ++i)
    {
        if (s[i] == 'B' && s[i+1] == 'A')
        {
            if (i == 0) index[i+2] = 1;
            else index[i+2] = index[i+1] + 1;
        }
        else
        {
            index[i+2] = index[i+1];
        }
    }
    for (int i = 0; i < s.length()-1; ++i)
    {
        if (s[i] == 'A' && s[i+1] == 'B')
        {
            if (index[i] >= 1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
}
/*
5
1 2 4 5 7
*/