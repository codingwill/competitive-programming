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
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll c1 = round(pow(a[n-1], double(1)/(n-1)));
    ll c2 = round(pow(a[n-1], double(1)/(n-1))) - 1LL;
    ll c3 = round(pow(a[n-1], double(1)/(n-1))) + 1LL;
    //cout << c << '\n';
    ll tujuan = 0;
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    for (int i = 0; i < n; ++i)
    {
        tujuan = pow(c1, i);
        ans1 += abs(a[i] - tujuan);
    }
    for (int i = 0; i < n; ++i)
    {
        tujuan = pow(c2, i);
        ans2 += abs(a[i] - tujuan);
    }
    if (pow(c3, n-1) < 1e18 + 1)
    {
        for (int i = 0; i < n; ++i)
        {
            tujuan = pow(c3, i);
            ans3 += abs(a[i] - tujuan);
        }
    }
    else ans3 = INT64_MAX;
    cout << min(ans1, min(ans3, ans2)) << '\n';

}
/*
3 12 6
6 12 3
*/