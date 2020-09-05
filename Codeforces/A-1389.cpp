#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        if (r / l < 2)
        {
            cout << -1 << ' ' << -1 << '\n';
            continue;
        }
        else
        {
            cout << l << ' ' << l*2 << '\n';
        }
        
    }
}