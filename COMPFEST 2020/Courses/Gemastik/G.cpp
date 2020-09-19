#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 998244353;

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
	//ios_base::sync_with_stdio(false);
    //.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<pair<ll, ll>> a;
    for (int x = 0; x < n; ++x)
    {
        ll n, m, r, s;
        cin >> n >> m >> r >> s;
        a.push_back(make_pair(abs(n-r), abs(m-s)));
    }
    for (ll i = 0; i < n-1; ++i)
    {
        bool can = false;
        for (ll j = i+1; j < n; ++j)
        {
            bool can = false;
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
                can = true;
            if (a[j].first >= a[i].first && a[j].second >= a[i].second)
                can = true;
            //cout << a[i].first << ' ' << a[i].second << ' ' << a[j].first << ' ' << a[j].second << '\n';
            swap(a[i].first, a[i].second);
            //cout << a[i].first << ' ' << a[i].second << ' ' << a[j].first << ' ' << a[j].second << '\n';
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
                can = true;
            if (a[j].first >= a[i].first && a[j].second >= a[i].second)
                can = true;
            swap(a[i].first, a[i].second);
            swap(a[j].first, a[j].second);
            //cout << a[i].first << ' ' << a[i].second << ' ' << a[j].first << ' ' << a[j].second << '\n';
            if (a[i].first >= a[j].first && a[i].second >= a[j].second)
                can = true;
            if (a[j].first >= a[i].first && a[j].second >= a[i].second)
                can = true;
            swap(a[j].first, a[j].second);
            if (!can)
            {
                ans++;
                //cout << i << ' ' << '\n';
            } 
        }
        
    }
    cout << ans << '\n';
}
/*
3 6 1 4 2 8 5 7
1 2
3
2 1
0
2 3
0
3 2
1
3 4
1
4 3
0
4 5
0
5 4
2
5 6
2
6 5
0
6 7
3
7 6
5
7 8
5
8 7
2

3 0 1 0 2 8 5 7

1 3 2
*/