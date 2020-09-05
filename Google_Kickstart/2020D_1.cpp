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
    int num = t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        ll count = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        
        ll maks = -1;
        if (n > 1)
        {
            if (a[0] > a[1])
            {
                ++count;
            }
            maks = max(maks, a[0]);
        }
        else count = 1;
        if (n >= 3)
        {
            for (int i = 1; i < n-1; ++i)
            {
                if (a[i] > maks && a[i] > a[i+1]) ++count;
                maks = max(maks, a[i]);
            }
        }
        if (n >= 2)
        {
            if (a[n-1] > maks)
            {
                ++count;
            }
        }
        cout << "Case #" << num-t << ": " << count << '\n';
    }
}