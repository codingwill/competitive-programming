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
 
 
bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void solve()
{
    int t;
    cin >> t;
    int total = t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n+10);
        vector<int> ans(n+10, 1000000);
        for (int i = 0; i < n; ++i)
        {
            int index = i + 1;
            int input;
            cin >> input;
            a[input].push_back(index);
        }
        for (int i = 1; i < n+1; ++i)
        {
            if (a[i].size() == 0) continue;
            int maks = a[i][0];
            for (int j = 1; j < a[i].size(); ++j)
            {
                maks = max(a[i][j] - a[i][j-1], maks);
            }
            maks = max((n+1) - a[i][a[i].size()-1], maks);
            ans[maks] = min(ans[maks], i);
        }
        for (int i = 1; i < n+1; ++i)
        {
            if (i > 1 && ans[i-1] != 1000000)
            {
                if (ans[i] != ans[i-1])
                {
                    ans[i] = min(ans[i], ans[i-1]);
                }
            }
            if (ans[i] == 1000000) cout << -1 << ' ';
            else cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}
 
/*
1
7 3
12 16
1 3
4 5
7 9
10 11
17 19
19 20
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 

K = 5
1 3
4 5
5 6
6 7
7 8
8 9
*/