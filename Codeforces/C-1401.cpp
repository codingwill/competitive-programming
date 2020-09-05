#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/16
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

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        if (n == 1 || is_sorted(a.begin(), a.end()))
        {
            cout << "YES" << '\n';
        }
        else
        {
            sort(b.begin(), b.end());
            ll gcd = -1;
            bool can = true;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] != b[i])
                {
                    if (a[i] % b[0] != 0)
                    {
                        can = false;
                    }
                }
            }
            //cout << gcd << '\n';
            cout << (can ? "YES" : "NO") << '\n';
        }
        
    }
}
/*
3 12 6
6 12 3
*/