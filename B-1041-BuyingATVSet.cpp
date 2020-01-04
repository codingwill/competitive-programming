#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll fpb = __gcd(x, y);
    x /= fpb;
    y /= fpb;
    cout << min(a / x, b / y) << '\n';
    cout << fpb << endl;
}