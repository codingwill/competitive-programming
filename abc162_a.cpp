#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - '0' == 7)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}