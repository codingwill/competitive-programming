#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
int kiri = 0, kanan = 0;
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

vector<vector<ll>> dp(1050, vector<ll>(25, 1));

void initDP()
{
    for (int i = 0; i < dp.size(); ++i)
    {
        dp[i][0] = i;
        if (i > 1) dp[i][1] = (dp[i][0] + dp[i-1][1]) % MOD; 
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    initDP();
    for (int j = 2; j < dp[0].size(); ++j)
    {
        for (int i = 2; i < dp.size(); ++i)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
        }
    }
    cout << dp[n][m*2 - 1] << '\n';
}
 
/* KOTRETAN
    1   2   3   4   5   ||  M
1   1   1   1   1   1
2   3   4   [5]
3   6   10  15 
4   10  20  35
5   15  35  70
6   21  56  126
7   28  84
8   36  120 
9   45
10  [55]
==
N
dp[1][2] = 1
dp[2][1] = 3
dp[2][2] = 4
dp[n][m] = dp[n][m-1] + dp[n-1][m];

ans = dp[n][m*2 - 1]

11 11
11 21
11 22
11 31
11 32
11 33
12 22
12 32
12 33
13 33
22 22
22 32
22 33
23 33
33 33
[15]



*/