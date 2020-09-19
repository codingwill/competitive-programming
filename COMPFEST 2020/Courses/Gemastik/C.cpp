#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 998244353;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 

double a, b, c, d, e, f, m1, m2;

void garis1(pair<double, double> p, pair<double, double> q) 
{ 
    a = q.second - p.second; 
    b = p.first - q.first; 
    c = a*(p.first) + b*(p.second); 
    a = (int)a / __gcd((int)abs(a), (int)abs(b));
    b = (int)b / __gcd((int)abs(a), (int)abs(b));
    m1 = (q.second - p.second) / (q.first - p.first);
    if (b < 0) 
    { 
       cout << a << "x " << b << "y = " << c << endl; 
    } 
    else
    { 
       cout << a << "x + " << b << "y = " << c << endl; 
    } 
} 
void garis2(pair<double, double> p, pair<double, double> q) 
{ 
    d = q.second - p.second; 
    e = p.first - q.first; 
    f = d*(p.first) + e*(p.second); 
    d = (int)d / __gcd((int)abs(d), (int)abs(e));
    e = (int)e / __gcd((int)abs(d), (int)abs(e));
    m2 = (q.second - p.second) / (q.first - p.first);
    if (e < 0) 
    { 
       cout << d << "x " << e << "y = " << f << endl; 
    } 
    else
    { 
        cout << d << "x + " << e << "y = " << f << endl; 
    } 
} 

void solve()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    garis1(make_pair(x1, y1), make_pair(x2, y2));
    cin >> x1 >> y1 >> x2 >> y2;
    garis2(make_pair(x1, y1), make_pair(x2, y2));
    if (a == d && b == e && c == f)
    {
        cout << "GARIS SAMA\n";
    }
    else if (abs(m1 - m2) <= 1e-3)
    {
        cout << "SEJAJAR\n";
    }
    else
    {
        ll lcm = (abs(a) * abs(d)) / __gcd((int)a, (int)d);
        //cout << lcm << '\n';
        b = b * (lcm/a);
        c = c * (lcm/a);
        e = e * (lcm/d);
        f = f * (lcm/d);
        a = a * (lcm/a);
        d = d * (lcm/a);
        //cout << b + e << '\n';
        double x, y;
        if (a + d == 0)
        {
            y = (c + f) / (b + e);
            x = (c - y * b) / a;
        }
        else
        {
            y = (c - f) / (b - e);
            x = (c - y * b) / a;
        }
        if (x < 0 && abs(x) < 1e-3) x = 0.00;
        if (y < 0 && abs(y) < 1e-3) y = 0.00;
        
        cout << fixed << setprecision(2) << x << " " << y << '\n';
    }
    
}
/*
2 3
4 1
2 0
5 3
*/