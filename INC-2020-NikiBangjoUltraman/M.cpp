#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const ll BIG = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

void solve();

ll fastpow(ll x, ll y, ll n = MOD)
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

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int xMin = INT32_MAX;
    int xMaks = INT32_MIN;
    int yMin = INT32_MAX;
    int yMaks = INT32_MIN;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        xMin = min(xMin, x);
        xMaks = max(xMaks, x);
        yMin = min(yMin, y);
        yMaks = max(yMaks, y);   
    }
    cout << (xMaks - xMin + 1) / 2 << ' ' << (yMaks - yMin + 1) / 2 << '\n';
}