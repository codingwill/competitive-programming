#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    while (t--)
    {
        cin >> s;
        int len = s.length();
        if (len == 1)
        {
            cout << "a" << endl;
            continue;
        }
        int i = 0;
        while (i < len-1)
        {
            if (s[i] != '?' && s[i] == s[i+1])
            {
                cout << "-1" << "\n";
                break;
            }
            i++;
        }
        if (s[i] != '?' && s[i] == s[i+1])
        {
            continue;
        }
        else
        {
            i = 0;
            while (i < len)
            {
                if (i != 0 && i < len-1 && s[i] == '?' && s[i+1] != '?' && s[i-1] != '?')
                {
                    if (s[i-1] == 'a' && s[i+1] == 'b')
                        s[i] = 'c';
                    else if (s[i-1] == 'a' && s[i+1] == 'c')
                        s[i] = 'b';
                    else if (s[i-1] == 'b' && s[i+1] == 'c')
                        s[i] = 'a';
                    else if (s[i-1] == 'b' && s[i+1] == 'a')
                        s[i] = 'c';
                    else if (s[i-1] == 'c' && s[i+1] == 'a')
                        s[i] = 'b';
                    else if (s[i-1] == 'c' && s[i+1] == 'b')
                        s[i] = 'a';
                    else if (s[i-1] == 'a' && s[i+1] == 'a')
                        s[i] = 'b';
                    else if (s[i-1] == 'b' && s[i+1] == 'b')
                        s[i] = 'a';
                    else if (s[i-1] == 'c' && s[i+1] == 'c')
                        s[i] = 'b';
                }
                else if (s[i] == '?')
                {
                    if (i == 0 && s[i+1] == '?')
                    {
                        s[i] = 'a';
                    }
                    else if (i == 0 && s[i+1] != '?')
                    {
                        s[i] = (int)s[i+1]+1;
                        if (s[i] > (int)'c')
                            s[i] = 'a';
                    }
                    else
                    {
                        s[i] = (int)s[i-1]+1;
                        if (s[i] > (int)'c')
                            s[i] = 'a';
                    }
                }
                i++;
            }
            cout << s << "\n";
        }
    }
}