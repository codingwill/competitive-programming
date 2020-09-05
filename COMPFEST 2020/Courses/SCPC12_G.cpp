#include <bits/stdc++.h>
#include <cstdio>
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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(100001, 0);
    for (int j = 0; j < 2*n; ++j)
    {
        int input;
        cin >> input;
        cnt[input]++;
    }

    int ans = 0;
    for (int x : cnt) ans = max(ans, x - n);
    ans <= k ? printf("Ya\n") : printf("Tidak\n");
    
}
/*
4 1
2 3 3 4
9 3 3 1

2 3 3 4
3 9 1 3

4 1
2 3 3 4
2 3 3 4

2 3 3 4
3 2 4 3
*/