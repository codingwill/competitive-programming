#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/02
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

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

bool sortPairFirst(pair<int, bool> &a, pair<int, bool> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
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
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll A = a, B = b, N = n;
        ll dec = min(n, abs(a - x));
        A = A - dec;
        N -= dec;
        if (N > 0)
        {
            dec = min(N, abs(B - y));
            B = B - dec;
            N -= dec;
        }
        ll ans = A * B;
        A = b, B = a, N = n;
        swap(x, y);
        dec = min(N, abs(A - x));
        A = A - dec;
        N -= dec;
        if (N > 0)
        {
            dec = min(N, abs(B - y));
            B = B - dec;
            N -= dec;
        }
        //cout << a << b << '\b';
        cout << min(ans, A*B) << '\n';
    }
}
/*

*/