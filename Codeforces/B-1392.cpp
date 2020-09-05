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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> a;
        for (int i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            a.push_back(make_pair(i, input));
        }
        sort(a.begin(), a.end(), sortPairVal);
        /*
        for (int i = 0; i < k; ++i)
        {
            ll maks;
            if (!(i & 1))
            {
                maks = a[n-1];
            }
            else
            {
                maks = a[0];
            }
            for (int j = 0; j < n; ++j)
            {
                a[j] = maks - a[j];
            }
            cout << i << ": " << '\n';
            for (int j = 0; j < n; ++j)
            {
                cout << a[j] << ' ';
            }
            cout << '\n';
        }
        */
        ll maks;
        maks = a[n-1].second;
        for (int j = 0; j < n; ++j)
        {
            a[j].second = maks - a[j].second;
        }
        if (!(k & 1))
        {
            maks = a[0].second;
            for (int j = 0; j < n; ++j)
            {
                a[j].second = maks - a[j].second;
            }
        }
        
        sort(a.begin(), a.end(), sortPairIndex);
        for (int i = 0; i < n-1; ++i)
        {
            cout << a[i].second << ' ';
        }
        cout << a[n-1].second << '\n';
    }
}

/*
1 2 3 4 5
k = 4
-2 -1 0 1 2 3
5 4 3 2 1 0
0 1 2 3 4
4 3 2 1 0

-8 -3 -9 4 9 6
17 12 18 5 0 3
*/