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


bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}



int sequence(int a, int b)
{
    ll res = 1; 
    for (ll i = b; i <= a; i++) 
        res = (res * i) % MOD; 
    return res; 
}

/*================ SOLUTION ================*/


void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        if (sum % (n-1) != 0)
        {
            ans = max(a[n-1], (sum/(n-1) + 1)) * (n-1) - sum;
        }
        else
        {
            ans = max(a[n-1], sum/(n-1)) * (n-1) - sum;
        }
        cout << ans << '\n';
    }
}
 
/* ========= KOTRETAN ========= \*
4
9 0 0 0
9 6 6 6

1 4
3 9 13 1
13
10 9 13 7

*/