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
        int n;
        cin >> n;
        if (n < 3) 
        {
            cout << 0 << '\n';
            continue;
        }
        (n % 2) == 0 ? cout << n/2 - 1 : cout <<  n/2;
        cout << '\n';
    }
    return 0;
}