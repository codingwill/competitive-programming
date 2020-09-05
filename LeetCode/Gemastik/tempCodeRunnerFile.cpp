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
    int ans = -1;
    for (int i = 0; i < n-1; ++i)
    {
        int len = 0;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] - a[i] == j - i)
            {
                len++;
                if (j == n-1 && a[j] != 1000) len--; 
                if (i == 0 && j == n-1) len++;
            }
            else break;
        }
        if (i > 0)
        {
            if (a[i] - a[i-1] != 1) len--;
        }
        else if (a[i] != 1) len--;
        ans = max(ans, len);
    }
    cout << ans << '\n';
}
/*

*/