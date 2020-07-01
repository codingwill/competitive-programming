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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 26)
    {
        cout << "NO" << '\n';
        return 0;
    }
    bool ada;
    for (char i = 'a'; (int)i <= (int)'z'; i++)
    {
        ada = false;
        for (int j = 0; j < s.length(); j++)
        {
            if (i == s[j] || toupper(i) == s[j])
            {
                ada = true;
                break;
            }
        }
        if (!ada) break;
    }
    if (ada) cout << "YES\n";
    else cout << "NO\n";
}