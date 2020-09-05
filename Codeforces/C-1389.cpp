#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<string, ll> countSolo, countDuoGenap, countDuoFinal;
        for (int i = 0; i < s.length(); ++i)
        {
            string key = s.substr(i, 1);
            countSolo[key]++;
        }
        for (int i = 0; i < s.length()-1; ++i)
        {
            
            string key = s.substr(i, 2);
            if (s[i] != s[i+1]) countDuoGenap[key]++;
        }
        /*
        for (int i = 1; i < s.length(); i += 2)
        {
            string key = s.substr(i, 2);
            countDuoGanjil[key]++;
        }
        */
        ll maks = -1;
        for (auto it = countSolo.begin(); it != countSolo.end(); ++it)
        {
            maks = max(maks, it->second);
        }
        string s2;
        ll ans = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            string temp;
            temp += s[i];
            if (countSolo[temp] >= maks)
            {
                s2 += s[i];
            }
            else
            {
                ans++;
            }
            
        }
        cout << s2 << endl;

        for (int i = 0; i < s2.length()-1; ++i)
        {
            string key = s2.substr(i, 2);
            if (s2[i] != s2[i+1]) countDuoFinal[key]++;
        }
        maks = -1;
        for (auto it = countDuoFinal.begin(); it != countDuoFinal.end(); ++it)
        {
            maks = max(maks, it->second * 2);
        }
        /*
        for (auto it = countDuoGanjil.begin(); it != countDuoGanjil.end(); ++it)
        {
            maks = max(maks, it->second * 2);
        }
        */
        //cout << countDuoGenap["21"] << '\n';
        cout << s2.length() - (maks) + ans << '\n';
        
    }
}

/*
1
12121021212
3

2121021210

1
121342
4
[2]
1212
2121
2121


*/