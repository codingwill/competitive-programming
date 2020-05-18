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
    int a = 24, b = 40;
    cout << a << ' ' << b << endl;
    cout << (a * b) / __gcd(a, b) << endl;
    cout << __gcd(a, b) << endl;
}
/*
4
10 24 40 80
*/