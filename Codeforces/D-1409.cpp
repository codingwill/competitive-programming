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
        string n;
        ll s;
        cin >> n >> s;
        ll sum = 0;
        for (int i = n.length()-1; i >= 0; --i)
        {
            sum += n[i] - '0';
        }
        ll ans = 0;
        ll base = 10;
        ll len = n.length();
        ll temp = 1;
        if (sum <= s) 
        {
            cout << 0 << '\n';
            continue;
        }
        for (ll i = n.length()-1; i >= 0; --i)
        {
            if (sum >= s)
            {
                ll satuan = n[i] - '0';
                if (i < len-1) 
                {
                    ans += ll(pow(base, len - i)) - (satuan + temp) * ll(pow(base, len - i - 1));
                }
                else 
                {
                }
                sum -= satuan;
            }
            else break;
        }
        cout << ans << '\n';
    }   
}
/*
217871987498122 10

217871987498130 10 +8
217871987498200 10 +78
217871987498800

10000000000000 
  7871987498122
*/