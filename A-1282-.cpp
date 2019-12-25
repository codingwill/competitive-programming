#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

using ll = long long int;

Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        ll maks = max(a, b), minim = min(a, b);
        ll maksRad = max(c+r, c-r), minRad = min(c+r, c-r);
        ll minCov = max(minim, minRad), maksCov = min(maksRad, maks);
        ll unavailable;
        if (!((minRad < minim && maksRad < minim) || (minRad > maks && maksRad > maks)))
        {
            unavailable = (maks-minim) - (maksCov-minCov);
        }
        else
        {
            unavailable = maks-minim;
        }
        /*
        cout << maks << endl;
        cout << minim << endl;
        cout << maksCov << endl;
        cout << minCov << endl;
        cout << maksRad << endl;
        cout << minRad << endl;
        */
        cout << unavailable << '\n';
    }
    return 0;
}