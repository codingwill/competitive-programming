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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        bool prime = true;
        for (int i = 2; i*i <= n; i++)
        {
            if (n % i == 0)
            {
                n += i;
                prime = false;
                break;
            }
        }
        if (!prime) ans += n + (k-1) * 2;
        else ans += (n+n) + (k-1) * 2;
        cout << ans << '\n';
    }
}
/*
+ (k-1) * 2
5 6
f(5) = 5, 5 + 5 = 10
f(10) = 2, 10 + 2 = 12
f(12) = 2, 12 + 2 = 14

9 4
3, 9 + 3 = 12
7, 7 + 7 = 14

*/