#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int dp[3][200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    set<char> key;
    while (t--)
    {
        string s;
        cin >> s;
        int l = 0, r = s.length()-1;
        //check 1 2 3
        for (int i = 0; i < s.length(); i++)
        {
            key.insert(s[i]);
        }
        if (key.size() < 3)
        {
            cout << 0 << '\n';
            key.clear();
            continue;
        }
        
        //left-right
        for (int i = 0; i < s.length(); i++)
        {
            key.insert(s[i]);
            if (key.size() == 3)
            {
                r = i;
                break;
            }
        }
        key.clear();
        //right-left
        for (int i = r; i >= 0; i--)
        {
            key.insert(s[i]);
            if (key.size() == 3)
            {
                l = i;
                break;
            }
        }
        //cout << l << ' ' << r <<endl;
        key.clear();
        cout << r - l + 1 << '\n';
    }
}

/*
12222133333332
213
3

112233
1223
4

12121212

0

31121
3112
4

31121
*/