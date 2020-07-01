#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/
 
using namespace std;
using ll = long long int;
 
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
        ll res = 0;
        ll init = 0;
        while (true)
        {
            ll cur = init;
            bool ok = true;
            for (int i = 0; i < s.length(); ++i)
            {
                res += 1;
                if (s[i] == '+')
                {
                    cur += 1;
                }
                else
                {
                    cur -= 1;
                }
                if (cur < 0)
                {
                    ok = false;
                    break;
                }
            }
            if (ok) break;
            ++init;
        }
        cout << res << '\n';
    }
}