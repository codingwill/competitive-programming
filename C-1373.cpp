#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;

int dpMinus[1000005], dpPlus[1000005];

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
        dpMinus[0] = 0;
        dpPlus[0] = 0;
        //dp start from 1
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '-')
            {
                dpMinus[i] = dpMinus[i-1] + 1;
                dpPlus[i] = dpPlus[i-1];
            }
            else
            {
                dpPlus[i] = dpPlus[i-1] + 1;
                dpMinus[i] = dpMinus[i-1];
            }
        }
        int maks = 0;
        for (int i = 0; i < s.length() ; ++i)
        {
            if (maks < dpMinus[i] - dpPlus[i])
            {
                maks = dpMinus[i] - dpPlus[i];
                res += i+1;
            }
        }
        res += s.length();

        cout << res << '\n';
    }
}

/*
----++-+-+---+
------
+++++
37
27
5
*/

/*
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
        */