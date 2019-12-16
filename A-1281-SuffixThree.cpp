#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    char akhir[3] = {'o', 'u', 'a'};
    string bahasa[3] = {"FILIPINO", "JAPANESE", "KOREAN"};
    while(t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < 3; i++)
        {
            if (s[s.length()-1] == akhir[i])
            {
                cout << bahasa[i] << '\n';
                continue;
            }
        }
    }
    return 0;
}