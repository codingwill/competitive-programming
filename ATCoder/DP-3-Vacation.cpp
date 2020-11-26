#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/11/20
*/
using namespace std;
using ll = long long int;

int MAXN = 300050;
ll BIG = 1e18 + 1;
ll MOD = 998244353;
int M = 998244353;
int kiri = 0, kanan = 0;
void solve();
vector<ll> inv(MAXN, 1), fac(MAXN, 1);
 
ll fastpow(ll x, ll y, ll n = M) 
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
 
bool sortPairFirst(pair<ll, ll> &a, pair<ll, ll> &b)
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

ll combin(ll n, ll k)
{
    if (k > n) return 0;
    ll ans = fac[n];
    ans = (ans * inv[n - k]) % MOD;
    ans = (ans * inv[k]) % MOD;
    
    return ans;
}

void preCombin()
{
    ll factorial = 1;
    fac[0] = 1;
    inv[0] = 1;

    for (int i = 1; i < MAXN; ++i) 
    {
        factorial = (factorial * i) % MOD;
        fac[i] = factorial;
        inv[i] = fastpow(fac[i], MOD-2);
    }
}

ll mod(ll a, ll b)
{
    return (a % b + b) % b;
}

/*================ SOLUTION ================*/


vector<vector<ll>> dp(3, vector<ll>(200050, 0));

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n+5, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    }

    //Dynamic Programming
    dp[0][0] = a[0][0];//base case
    dp[1][0] = a[1][0];
    dp[2][0] = a[2][0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j) //3 cara untuk melakukan aktivitas dalam hari pertama
        {
            for (int k = 0; k < 3; ++k) //2 cara untuk melakukan aktivitas di hari kedua 
            {
                if (j == k) continue; //kalo harinya sama diskip, karena ga boleh repetitif
                dp[j][i] = max(dp[j][i], dp[k][i-1] + a[j][i]);
            }
        }
    }
    cout << max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1])) << '\n';
}
 
/* ========= KOTRETAN ========= \*

5 2
1 3
2 4
3 5
4 6
5 7

1 3
2 4
3 5
4 6
5 7

3 5 -> n = 2
C(n, k) + 

*/