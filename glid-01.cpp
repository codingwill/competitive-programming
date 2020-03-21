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
    ll n;
    cin >> n;
    while (n--)
    {
        string x;
        cin >> x;
        int maks = -1;
        for (int i = 0; i < x.length(); i++)
        {
            maks = max(maks, x[i] - '0');
        }
        cout << maks << '\n';
    }
}