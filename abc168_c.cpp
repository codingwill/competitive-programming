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
    double a, b, h, m;
    double const phi = 2*acos(0.0);
    cin >> a >> b >> h >> m;
    h += m/60;
    m /= 5;
    double rad = min(abs(h - m), abs(12-h) + m)/12 * 2 * phi;
    cout << setprecision(18) << sqrt(a*a + b*b - 2*a*b*cos(rad)) << endl; //KETEMU ATURAN COSINUS SETELAH SEKIAN LAMA >w<
}

/*
a + b = d
a * b = d

a + b = a * b
a = d/b
d/b + b = d
(d + b*b)/b = d
d + b*b = b*d
b*b = b*d - d
b*b = d * (b - 1)
b*b / (b-1) = d
*/