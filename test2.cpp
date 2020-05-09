#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t, z;
        map<char, int> m;
        set<char> tSet;
        cin >> s >> t;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++)
        {
            tSet.insert(t[i]);
        }
        set<char>::iterator it;
        bool found = true;
        for (it = tSet.begin(); it != tSet.end(); it++)
        {
            cout << *it << '\n';
            if (m[*it] == 0)
            {
                found = false;
            }
        }
        if (!found)
        {
            cout << "-1" << '\n';
            continue;
        }
        int ans = t.length();
        for (int i = 0; i < t.length(); i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                
            }
        }


        
    }
}