#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans;
        bool ada = false, last = false;
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s.length() % (i+1) == 0)
            {
                for (int j = i+1; j < s.length(); j += (i+1))
                {
                    if (s.substr(0, i+1) == s.substr(j, i+1))
                    {
                        if (j == s.length() - (i+1)) 
                        {
                            ans = s.substr(0, i+1);
                            ada = true;
                            break;
                        }
                    }
                    else break;
                }
            }
            if (ada) break;
        }
        if (ada) cout << ans.c_str() << '\n';
        else cout << s.c_str() << '\n';
    }
}