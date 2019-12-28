#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}
using ll = long long int;

int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll nKidsMax = k/2;
        ll nKidsMin = k - k/2;
        ll ans = (n / k)*k + nKidsMax;
        if (n % k != 0 && ans < n) cout << ans;
        else cout << n;
        cout << '\n';
    }
    return 0;
}