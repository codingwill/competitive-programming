#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/11/23
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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

int n, m, k;
int dp[71][71][71][71];

void solve()
{
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 70, INT32_MIN);
    dp[0][0][a[0][0] % k][1] = a[0][0];
    int sisa = 0;
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        for (int j = 0; j <= m; ++j)
        {
            //int *curState = dp[i][j][count + 1][(sisa + a[i][j]) % k];
            if (i == 0 && j == 0) continue;
            if (count >= m/2) 
            {
                if (j > 0)
                    dp[i][j][count][sisa] = max(dp[i][j][count][sisa], dp[i][j-1][count][sisa]);
                else
                    dp[i][j][count][sisa] = max(dp[i][j][count][sisa], dp[i-1][m-1][count][sisa]);
            }
            else
            {
                if (j > 0)
                {
                    dp[i][j][count + 1][(sisa + a[i][j]) % k] = max(dp[i][j][count][(sisa + a[i][j]) % k] + a[i][j], dp[i][j-1][count][(sisa + a[i][j]) % k]);
                    if (dp[i][j][count][(sisa + a[i][j]) % k] + a[i][j] > dp[i][j-1][count][(sisa + a[i][j]) % k])
                    {
                        count++;
                        sisa = (sisa + a[i][j]) % k;
                    }
                }
                else
                    dp[i][j][count + 1][(sisa + a[i][j]) % k] = max(dp[i][j][count][(sisa + a[i][j]) % k] + a[i][j], dp[i-1][m-1][count][(sisa + a[i][j]) % k]);
                
            }
            //curState = max(curState, );
        }
    }
    cout << max(0, dp[n-1][0][0][0]) << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            cout << dp[i][j][1][1] << ' ';
        }
        cout << '\n';
    }
}
 
/* ========= KOTRETAN ========= \*
    -   A   X   Y   B
-   0   0   0   0   0
A   0   1   1   1   1
B   0   1   1   1   2
Y   0   1   1   2   2
X   0   1   2   2   2
B   0   1   2   2   3

    -   A   X   Y   B
-   0   0   0   0   0
A   0   *   -   -   -
B   0   -   -   -   *
Y   0   -   -   *   -
X   0   -   *   -   -
B   0   -   -   -   *
*/
