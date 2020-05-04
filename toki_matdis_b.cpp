#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ll a, b, c, d;
    ll e, f;
    cin >> a >> b >> c >> d;
    f = (b*d) / __gcd(b, d); //LCM aka KPK
    e = a*(f/b) + c*(f/d);
    ll gcd_ef = __gcd(e,f);
    e = e / gcd_ef;
    f = f / gcd_ef;
    cout << e << ' ' << f << '\n';
}