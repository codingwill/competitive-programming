#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string sDecode;
    int i = 0;
    while (n--)
    {
        if (n % 2 == 1)
        {
            sDecode.insert(0, s.substr(i, 1));
        }
        else
        {
            sDecode.insert(i, s.substr(i, 1));
        }
        i++;
    }
    cout << sDecode << '\n';
    return 0;
}