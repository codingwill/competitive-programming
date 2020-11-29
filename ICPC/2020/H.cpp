#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/11/29
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
int m = 998244353;
int kiri = 0, kanan = 0;
void solve();
 
ll fastpow(ll x, ll y, ll n = m) 
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

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        //cout << middle << '\n';
        //if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle) kiri++;
        }
        else
        {
            right = middle;
            kanan++;
        }
    }
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
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b;
    int prev = 1e9 + 5;
    for (int i = 0; i < m; ++i)
    {
        int input;
        cin >> input;
        if (input <= prev)
        {
            if (i > 0) b.push_back(prev);
            if (i == m-1)
            {
                b.push_back(input);
            }
        }
        prev = input;
    }
    int ans = 0;
    for (int i = 0; i < min(b.size(), a.size()); ++i)
    {
        if (b[i] >= a[i]) ans++;
    }
    cout << ans << '\n';
    


}
 
/* ========= KOTRETAN ========= \*

0 0 1 2 1 0
0 1 1 1 1 0 = 4
0 0 1 1 1 1 = 4

1500 1000
*/