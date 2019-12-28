#include <bits/stdc++.h>
 
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
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        vector<pair<char, int>> init;
        cin >> s1;
        int count = 1;
        int initIndex = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (i == 0)
            {
                init.push_back(make_pair(s1[i], count));
                continue;
            }
            if (s1[i] != s1[i-1])
            {
                count = 1;
                init.push_back(make_pair(s1[i], count));
            }
            else
            {
                init.back().second++;
            }
        }
        for (int i = 0; i < init.size(); i++)
        {
            s2.append(init[i].first + to_string(init[i].second));
        }
        //cout << s2 << endl;
        s1.length() > s2.length() ? cout << "YES\n" : cout << "NO\n";
    }
}