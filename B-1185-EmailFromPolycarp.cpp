#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; 
    cin >> n;
    while (n--)
    {
        string s, t;
        cin >> s >> t;
        vector<pair<char, int>> sChar, tChar;
        int charPos = 0;
        sChar.push_back(make_pair(s[0], 1));
        tChar.push_back(make_pair(t[0], 1));
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i-1]) 
            {
                sChar.push_back(make_pair(s[i], 1));
                charPos++;
            }
            else
            {
                sChar[charPos].second++;
            }
        }
        charPos = 0;
        for (int i = 1; i < t.length(); i++)
        {
            if (t[i] != t[i-1]) 
            {
                tChar.push_back(make_pair(t[i], 1));
                charPos++;
            }
            else
            {
                tChar[charPos].second++;
            }
        }
        if (sChar.size() != tChar.size())
        {
            cout << "NO" << '\n';
            continue;
        }
        bool can = true;
        for (int i = 0; i < sChar.size(); i++)
        {
            if (tChar[i].first != sChar[i].first || tChar[i].second < sChar[i].second)
            {
                can = false;
            }
        }
        if (can) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        /*
        for (int i = 0; i < sChar.size(); i++)
        {
            cout << sChar[i].first << " = " << sChar[i].second << endl;
        }
        for (int i = 0; i < tChar.size(); i++)
        {
            cout << tChar[i].first << " = " << tChar[i].second << endl;
        }
        */
    }
    return 0;
}
