#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, x, y;
        cin >> x >> y;
        cin >> a >> b;
        ll minim = min((abs(x-y)*a + min(x, y)*b), (x+y)*a);
        cout << minim << '\n';
    }
}
