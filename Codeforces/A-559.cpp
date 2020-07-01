#include<bits/stdc++.h>
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
    int a[6];
    int maks = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
        if (i > 0)
        {
            if (a[i] > a[i-1])
            {
                maks = i;
            }
        }
    }
    ll ans = pow(a[maks] + a[maks == 0 ? 5 : maks-1] + a[maks == 5 ? 0 : maks+1], 2);
    ans = ans - pow(a[maks == 0 ? 5 : maks-1], 2) - pow(a[maks == 5 ? 0 : maks+1], 2) - pow(a[maks >= 3 ? maks-3 : maks+3], 2);
    cout << ans << '\n';
}

/*
 3 5 7
1 4 9 16
*/
