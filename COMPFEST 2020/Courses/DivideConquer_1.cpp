#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
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
    ll n, a, b;
    cin >> n >> a >> b;
    ll r = 1e18;
    ll l = 1;
    ll mid = l + (r-l) / 2;
    ll count = 0;
    int ans = 1;
    int i = 0;
    while (true)
    {
        count = ((mid/a + mid/b) - (mid / (a*b / __gcd(a, b))));

        if (count > n) r = mid - 1;
        else if (count < n) l = mid + 1;
        else break;
        mid = l + (r-l)/2;
        //cout << count << ' ' << l << ' ' << r << '\n';
        //if (i == 10) break;
        i++;
    }
    cout << mid - min(mid % a, mid % b) << '\n';
}
/*

*/