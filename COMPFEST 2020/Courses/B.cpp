#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
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

bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
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
    ll n, m;
    cin >> n >> m;
    if (n / m > 5 || m > n) cout << "-1 -1" << '\n';
    else
    {
        ll l = 0, r = n;
        ll mid;
        //if (((l + 1) + (r / 2)) % 5 == 0)
        //{
            mid = l + ((r-l) / 2);
        //}
        //else mid = (1 + (l + 1) + (r / 2)) / 5) * 5;
        ll maks = -1;
        ll minim = INT64_MAX;
        while (l < r)
        {
            ll lima = mid / 5;
            if ((n - mid + (mid % 5)) / (m - lima) >= 1)
            {
                l = mid + 1;
                mid = l + ((r-l) / 2);
            }
            else
            {
                r = mid - 1;
                mid = l + ((r-l) / 2);
            }
            maks = max(maks, mid / 5);
            //cout << l << ' ' << r << '\n';
            //cout << ' ' << mid << '\n';
        }
        l = 0;
        r = n;
        mid = l + ((r-l) / 2);
        while (l < r)
        {
            ll lima = mid / 5;
            if (double(n - mid + (mid % 5)) / (m - lima) > 4)
            {
                l = mid + 1;
                mid = l + ((r-l) / 2);
            }
            else
            {
                r = mid - 1;
                mid = l + ((r-l) / 2);
            }
            minim = min(minim, mid / 5);
            //cout << l << ' ' << r << '\n';
            //cout << ' ' << mid << '\n';
        }
        cout << minim << ' ' << maks << '\n';
    }
    
}
/*
100 25
19

9 2
1 2


*/
