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
        ll l, r, m;
        cin >> l >> r >> m;
        for (int i = l; i <= r; ++i)
        {
            if (m > i)
            {
                if ((r - l) >= (m % i))
                {
                    cout << i << ' ' << r << ' ' << r - (m % i)  << '\n';
                    break;
                } 
                ll temp = (m/i + 1) * i;
                if (m - temp >= (l - r))
                {
                    cout << i << ' ' << r - (temp % m) << ' ' << r <<'\n';
                    break;
                }
            }
            else if (m < i)
            {
                
                if ((l - r) <= m - i)
                {
                    cout << i << ' ' << l << ' ' << l - (m - i)  << '\n';
                    break;
                }  
            }
            else
            {
                cout << i << ' ' << i << ' ' << i << '\n';
                break;
            }
            
        }
    }   
}
