#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool highFirst(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    if (s.length() != t.length())
    {
        cout << "No" << '\n';
        return 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
        {
            if (!(t[i] == 'a' || t[i] == 'i' || t[i] == 'u' || t[i] == 'e' || t[i] == 'o'))
            {
                cout << "No" << '\n';
                return 0;
            }
        }
        else
        {
            if (t[i] == 'a' || t[i] == 'i' || t[i] == 'u' || t[i] == 'e' || t[i] == 'o')
            {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
    return 0;
}