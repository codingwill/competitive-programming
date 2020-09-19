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
 
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int index = 0;
    vector<int> ans(n);
    if (n <= 2)
    {
        cout << 0 << '\n';
        for (auto n : a) cout << n << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i < n; i += 2)
    {
        ans[i] = a[index];
        index++;
    }
    for (int i = 0; i < n; i += 2)
    {
        ans[i] = a[index];
        index++;
    }
    ll count = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (i == n-1) break;
        if (ans[i] < ans[i-1] && ans[i] < ans[i+1])
            count++;
    }
    cout << count << '\n';
    for (auto n : ans) cout << n << ' ';
    cout << '\n';
}
 
/*
 
3 1 4 2 5
1 1 1 1 1 
 
7 1 6 2 4 3 5
*/