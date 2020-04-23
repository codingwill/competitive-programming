#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

const int MOD = 1e9 + 7;

ll bigPow(ll x, ll y) 
{
    if (y == 0) return 1;
    if (y % 2 == 1) return ((x * bigPow(x, y-1))) % MOD;
    ll t = bigPow(x, y/2);
    return ((t) * (t)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, a;
        cin >> n >> a;
        ll red = a;
        ll count = 0;
        ll bef = a;
        ll sum = red;
        for (int i = 2; i <= n; i++)
        {
            count = 2*i - 1;
            red = red * bef;
            bef = red;
            red = bigPow(red, count);
            sum = (sum + red) % MOD;
            //cout << red << endl;
        }   
        cout << sum << '\n';
    }
}