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
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    ll ans = (((a[1] + a[0]) + a[1]) * a[0]) + (((a[3] + a[4]) + a[4]) * a[3]);
    cout << ans << '\n';
}