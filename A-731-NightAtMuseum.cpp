#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    char bef = 'a';
    int cara = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int first = abs((int)s[i] - (int)bef);
        cara += min(first, 26 - first);
        bef = s[i];
    }
    cout << cara << '\n';
    return 0;
}