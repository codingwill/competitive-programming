#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/28
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
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> brac;
        int goodCount = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(') brac.push(s[i]);
            if (!brac.empty())
            {
                if (s[i] == ')')
                {
                    ++goodCount;
                    brac.pop();
                }
            }
        }
        cout << (n - (goodCount * 2)) / 2 << '\n';
    }
}

/*

()))((()
)((())

)))((((()())

*/