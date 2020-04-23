#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string ans[t];
    for (int z = 0; z < t; z++)
    {
        string s;
        cin >> s;
        string sInit = s;
        int index = -1;
        for (int i = 1; i < sInit.length(); i++)
        {
            //cout << i << '\n';
            string s1 = s.substr(0, i);
            string s2 = s.substr(s.length()-i, i);
            //cout << s1 << ' ' << s2 << '\n';
            if (s1 == s2) 
            {
                index = i+1;
            }
        }
        if (index != -1) s = s + s.substr(index-1, s.length()-(index-1));  
        if (s.length() == 1) s = s + s;
        ans[z] = s;
    }
    for (string n : ans) cout << n << '\n';
    return 0;
}