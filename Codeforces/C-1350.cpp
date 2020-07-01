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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll kpk = 0;
    ll fpb = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        kpk = (a[i] * fpb) / __gcd(a[i], fpb);
        ans = __gcd(ans, kpk);
        fpb = __gcd(fpb, a[i]);
    }
    cout << ans << '\n';
}
/*
2 40 240 154 18 375
18 54 427680 
1 1 1

4
10 24 40 80

2 5 
2 2 2 3
2 2 2 5
2 2 2 2 5

5 3 5 5 = 18

120 80
GCD(120, 80) = 40

4
10 24 40 80
24 10 6 3

4
3 1 4 2
2 4 1 3

5
5 2 4 1 3
1 3 5 2 4
2 4 1 3 5

6
5 2 4 1 3 6
1 3 5 2 4 6
2 4 6 3 1 5

10
2 4 6 8 10 7 9 5 3 1

9
1 3 5 7 9 6 8 4 2

11
1 3 5 7 9 11 8 10 6 4 2
*/