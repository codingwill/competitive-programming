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
        ll n, x, y;
        cin >> n >> x >> y;
        n--;
        ll diff = abs(x-y);
        ll inc = 0;
        for (int i = 1; i <= diff; i++)
        {
            if (diff % i == 0)
            {
                if (i * n >= diff)
                {
                    inc = i;
                    break;
                }
            }
        }
        
        ll ans = y;
        while (ans > 0)
        {
            if (n < 0) break;
            cout << ans << ' ';
            ans -= inc;
            n--;
        }
        ans = y + inc;
        while (n >= 0)
        {
            cout << ans << ' ';
            ans += inc;
            n--;
        }
        cout << '\n';
    }   
}
/*

*/