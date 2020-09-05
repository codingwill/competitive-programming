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
        ll n, k;
        cin >> n >> k;
        if (n >= k) 
        {
            if (!(k & 1))
            {
                if (n & 1) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else
            {
                if (!(n & 1)) cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            
        }
        else cout << k-n << '\n';
    }
}

/*
14 10 
0 2 14
2 - 12 = 10
3 - 13
B = 2
step = 0

13 10
B = 2 / 1
step = 1

15 10
B = 3 / 2
step = 1

12 11

1

0 1 13
| 1 - 12 | = 11
0 2 15
2 - 13
0 3 17
3 - 14

*/