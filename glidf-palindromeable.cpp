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
    int z = 0;
    while (t--)
    {
        string s;
        cin >> s;
        string sInit = s;
        vector<int> huruf;
        map<char, int> hurufCount;
        int ganjil = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (hurufCount[s[i]] < 1)
            {
                huruf.push_back(s[i]);                
            }
            hurufCount[s[i]]++;
        }
        //cout << huruf.size() << endl;
        for (int i = 0; i < huruf.size(); i++)
        {
            if (hurufCount[huruf[i]] % 2 == 1)
            {
                ganjil++;
            }
        }
        if (ganjil < 2) ans[z] = "PALINDROMEABLE";
        else ans[z] = "UNPALINDROMEABLE";
        z++;
    }
    for (string n : ans) cout << n << '\n';
    return 0;

}
/*
LUCINTALUNACIN -> LUCINATANNICUL
*/