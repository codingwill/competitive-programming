#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
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
        int n, q;
        cin >> n >> q;
        int init = 0;
        int count = 0;
        for (int i = 0; i < q; i++)
        {
            int f, d;
            cin >> f >> d;
            count += abs(init - f);
            init = f;
            count += abs(init - d);
            init = d;
        }
        cout << count << '\n';
    }
}