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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        a.push_back(x);
        ll minus = 0, plus = 0;
        bool infected = false;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (x - a[i] > 0) minus += abs(x - a[i]);
            else plus += abs(x - a[i]);
            if (a[i] == x) infected = true; 
        }
        sort(a.begin(), a.end());
        //for (auto n : a) cout << n << ' ';
        //cout << '\n';

        if (plus == minus)
        {
            if (plus == 0 && minus == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else
        {
            //cout << plus << ' ' << minus << '\n';
            //int aver = (plus-minus) / n;
            //for (auto n : a) cout << aver - n << ' ';
            if (infected) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        
    }
}

/*
9 38
-21 83 50 -59 -77 15 -71 -78 20

+59 -45 -12 +97 +115 +23 +109 +116 +18

*/