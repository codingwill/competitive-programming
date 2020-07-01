#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool sortChar(const char &a, const char &b)
{
    if ((int)a == (int))
    return (int)a < (int)b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string ans[n];

    for (int z = 0; z < n; z++)
    {
        int ganjil = 0;
        string s;
        cin >> s;
        map<char, int> karakter;
        vector<char> listChar;
        for (int i = 0; i < s.length(); i++)
        {
            if (karakter[s[i]] == 0) listChar.push_back(s[i]);
            karakter[s[i]]++;
        }
        for (int i = 0; i < listChar.size(); i++)
        {
            if (karakter[listChar[i]] % 2 == 1) ganjil++;
        }
        if (ganjil > 1)
        {
            ans[z] = "IMPOSSIBLE";
            continue;
        }
        sort(listChar.begin(), listChar.end());
        for (int i = 0; i < listChar.size(); i++)
        {
            for (int j = 0; j < karakter[listChar[i]]/2; j++)
            {
                ans[z] += listChar[i];
            }
        }
        string s2 = ans[z];
        reverse(s2.begin(), s2.end());
        ans[z] = ans[z] + s2;
        for (int i = 0; i < listChar.size(); i++)
        {
            if (karakter[listChar[i]] % 2 == 1 && karakter[listChar[i]] >= 1)
            {
                ans[z].insert(ans[z].length()/2, 1, listChar[i]);
            }
        }
        
    }
    for (string n : ans) cout << n << '\n';
    return 0;
}