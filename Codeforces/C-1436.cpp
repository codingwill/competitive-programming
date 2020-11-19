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

int kiri = 0, kanan = 0;

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

void solve()
{
    int n, x, pos;
    cin >> n >> x >> pos;
    binsearch(n, pos);
    ll total = fact(n - 1 - (kanan+kiri)) % MOD;
    total = (total * sequence(n-x, (n-x) - (kanan-1))) % MOD;
    //cout << sequence(n-x, (n-x) - (kanan-1)) << ' ' << sequence(x-1, x - 1 - (kiri-1)) << '\n';
    total = (total * sequence(x-1, (x-1) - (kiri-1))) % MOD;
    cout << total << '\n';
    cout << kiri << ' ' << kanan << '\n';
}
 
/*
1 2 3 4


1 2 3 4
2 1 3 1

824071958
234208388
955973230
824071958


123 42 24

123 24 42
0 123 61 kanan
0 61 30 kiri
31 61 46 kanan
31 46 38 kiri
38 46 42 -
42 46 44 kanan
42 44 43 kanan
42 43 42 -
42 42 42 -
kanan = 4, kiri = 2
*/