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

ll dpKiri[200005], dpKanan[200005];

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    dpKiri[0] = 1;
    dpKanan[n-1] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i > 0)
        {
            if (a[i] > a[i-1]) dpKiri[i] = dpKiri[i-1] + 1;
            else dpKiri[i] = 1;
        } 
    }

    for (int i = n-2; i >= 0; --i)
    {
        if (a[i] < a[i+1]) dpKanan[i] = dpKanan[i+1] + 1;
        else dpKanan[i] = 1;
    }
    ll maks = -1;
    for (int i = 0; i < n; ++i)
    {
        //kalo ga dihapus
        maks = max(maks, dpKiri[i]);
        //kalo dihapus
        if (i == 0) maks = max(maks, dpKanan[i+1]);
        else if (i == n-1) maks = max(maks, dpKiri[i-1]);
        else 
        {
            if (a[i+1] > a[i-1])   
                maks = max(maks, dpKiri[i-1] + dpKanan[i+1]);
        }
    }
    cout << maks << '\n';
    //cout << 1LL << '\n';
}