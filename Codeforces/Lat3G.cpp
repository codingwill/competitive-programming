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
        ll bola[4];
        vector<ll> sisa(4, 0);
        ll nol = 0, total = 0;
        for (int i = 0; i < 4; ++i)
        {
            cin >> bola[i];
            total += bola[i];
            if (bola[i] != 0) 
            {
                sisa[i] = bola[i] % 2;
                nol++;
            }
        }
        bool can = true;
        if (nol == 2)
        {
            ll sum = 0;
            for (int i = 0; i < 4; ++i)
            {
                sum += sisa[i];
            }
            if (total % 2 == 0)
            {
                if (sum > 0) can = false;
            }
        } 
        else if (nol == 1)
        {
            if (total % 3 == 0)
            {
                if (sum > 0) can = false;
            }
            if (total )
        }
    }
}