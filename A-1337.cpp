#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << a << ' ' << c << ' ' << c << '\n';
    }
    return 0;
}