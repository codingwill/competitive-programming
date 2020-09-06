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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
    }
    //increasing
    sort(a.begin(), a.end(), sortPairFirst);
    int changes = 0;
    bool incr = true;
    bool decr = true;
    int state = 0;
    for (int i = 1; i < n; ++i)
    {
        if (state == 1)
        {
            if (a[i].second - a[i-1].second < 0)
            {
                changes++;
            }
        }
        else if (state == -1)
        {
            if (a[i].second - a[i-1].second > 0)
            {
                changes++;
            }
        }
        if (a[i].second - a[i-1].second > 0) state = 1;
        else if (a[i].second - a[i-1].second < 0) state = -1;
    }
    if (changes > 1) incr = false;
    //decreasing
    sort(a.begin(), a.end(), sortPairFirstDec);
    state = 0;
    for (int i = 1; i < n; ++i)
    {
        if (state == 1)
        {
            if (a[i].second - a[i-1].second < 0)
            {
                changes++;
            }
        }
        else if (state == -1)
        {
            if (a[i].second - a[i-1].second > 0)
            {
                changes++;
            }
        }
        if (a[i].second - a[i-1].second > 0) state = 1;
        else if (a[i].second - a[i-1].second < 0) state = -1;
    }
    if (changes > 1) decr = false;

    if (decr || incr) cout << "Ya\n";
    else cout << "Tidak\n";
}
/*
5
1 5 2 4 3

5
3 5 2 4 1

1 2 3 4 5
4 2 0 3 1

*/