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
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a)
        {
            cout << b << '\n';
            continue;
        }
        if (c <= d)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << b + ((ll)ceil((float)(a-b) / (c-d)) * c)<< '\n';
    }
}
/*
358578060125049
358577698673813
*/