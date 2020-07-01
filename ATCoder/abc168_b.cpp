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
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (s.length() <= k) cout << s << endl;
    else
    {
        cout << s.substr(0, k) << "..." << endl;
    }
    return 0;
}