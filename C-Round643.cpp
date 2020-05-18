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
    vector<int> pre(500005, 0);
    vector<int> pola(500005, 0); 
    int n = 500001;
    //generate pre
    for (int i = 1; i <= 500000; i++)
    {
        pre[i] = i;
        pola[i] = pola[i-1] + i;
    }
    //lower bound - 1
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    //cout << ((a + b - 1) - c + 1) + ((b + c - 1) - c + 1) << '\n';
    ll ans = 0;
    ans += pola[upper_bound(pre.begin(), pre.end(), d-c) - pre.begin()] 
    ans += (b - (upper_bound(pre.begin(), pre.end(), d-c) - pre.begin())
             * (upper_bound(pre.begin(), pre.end(), d-c) - pre.begin()));
    cout << ans << '\n';
}
/*
1 1
2 3
3 6
4 10

1 5 8 11
sisi ke-3 = 8
1 + 8 > {8}
2 + 8 > {8, 9}
3 + 8 > {8, 9, 10}
4 + 8 > {8, 9, 10, 11}
5 + 8 > {8, 9, 10, 11}
cara1: (b - a + 1) * ((lb_3(a+b) + 1) <= d ? (lb_3(a+b) + 1) - c + 1 : (d-c)

cara2: pola[upperbound(d-c)] + (b - upperbound(d-c)) * upperbound(d-c)
)
2 + 7 > {8}

1 2 3 4
b = 2 
pola[2] = 3
3 + 


1 2 2 5

max 2
(min(x1, x2) + min(y1, y2) - 1) - min(z1, z2) + 1 = 1
(max(x1, x2) + max(y1, y2) - 1) - min(z1, z2) + 1 = 3
()  

*/