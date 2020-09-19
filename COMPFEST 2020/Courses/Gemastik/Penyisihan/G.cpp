#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
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

int kiri[105][10005];
int kanan[105][10005];


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        for (int j = 0; j < 101; ++j)
        {
            if (i > 0) kiri[j][i] = kiri[j][i-1];
            if (a[i] == i) kiri[j][i]++;
        }
    }
    for (int i = n-1; i >= 0; --i)
    {
        for (int j = 0; j < 101; ++j)
        {
            if (i < n-1) kanan[j][i] = kanan[j][i+1];
            if (a[i] == i) kanan[j][i]++;
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        int total = ((n - 1) - i);
        int r = i + 1;
        while (i < j)
        {}
    }
}

/*
6
10 20 30 50 40 10
10 20 30 40 50 50 30 10

6
1 2 3 1 2 3
1 2 3 1 2 3
*/