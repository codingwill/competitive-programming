#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/03
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    map<char, char> adj;
    set<char> exist;
    while (t--)
    {
        adj.clear();
        exist.clear();
        string s;
        cin >> s;
        bool possible = true;
        if (s.length() > 1)
        {
            vector<bool> used(26);
            used[s[0] - 'a'] = true;
            string ans;
            ans += s[0];
            int pos = 0;
            for (int i = 1; i < s.length(); i++) 
            {
                if (used[s[i] - 'a']) 
                {
                    if (pos > 0 && ans[pos - 1] == s[i]) 
                    {
                        pos--;
                    } 
                    else if (pos + 1 < ans.length() && ans[pos + 1] == s[i]) 
                    {
                        pos++;
                    } 
                    else 
                    {
                        possible = false;
                        break;
                    }
                } 
                else 
                {
                    if (pos == 0) 
                    {
                        ans = s[i] + ans;
                    } 
                    else if (pos == ans.length() - 1) 
                    {
                        ans += s[i];
                        pos++;
                    } 
                    else 
                    {
                        possible = false;
                        break;
                    }
                }
                used[s[i] - 'a'] = true;
            }
            if (possible) 
            {
                cout << "YES" << '\n';
                for (int i = 0; i < 26; ++i)
                {
                    if (!used[i])
                    {
                        ans += (char)i + 'a';
                    }
                }
                cout << ans << '\n';
            }
            else cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            exist.insert(s[0]);
            cout << s[0];
            char layoutKey = 'a';
            for (int i = 0; i < 26; ++i)
            {
                if (exist.find(layoutKey) == exist.end())
                {
                    cout << layoutKey;
                }
                ++layoutKey;
            }
            cout << '\n';
        }
        
        
       
    }
}

/*
1
iopoiopc
YES
ciopabdefghjklmnqrstuvwxyz
*/