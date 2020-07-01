#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<string> s;
    while (n--)
    {
        string input;
        cin >> input;
        s.insert(input);
    }
    cout << s.size() << '\n';
}