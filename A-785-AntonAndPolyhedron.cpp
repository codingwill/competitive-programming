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
    ll count = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "Tetrahedron") count += 4;
        else if (s == "Cube") count += 6;
        else if (s == "Octahedron") count += 8;
        else if (s == "Dodecahedron") count += 12;
        else if (s == "Icosahedron") count += 20;
    }
    cout << count << '\n';
    return 0;
}