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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    int len;
    len = 1;
    int start = 0, last = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            if (a[i] - a[i-1] == 1)
            {
                last = i;
                len++;
            }
            else
            {
                
                if (a[start] == 1)
                {
                    if (start == 0) len--;
                }
                else if (a[last] == 1000)
                {
                    if (last = n-1) len--;
                }
                else len -= 2;
                //cout << len << '\n';
                ans = max(ans, len);
                start = i;
                len = 1;
            }
        }
    }
    if (a[start] == 1)
    {
        if (start == 0) len--;
    }
    else if (a[last] == 1000)
    {
        if (last = n-1) len--;
    }
    else len -= 2;
    ans = max(ans, len);

    if (n == 1) cout << 0 << '\n';
    else cout << ans << '\n';
}
/*

*/