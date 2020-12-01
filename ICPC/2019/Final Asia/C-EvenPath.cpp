#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/12/01
*/
using namespace std;
using ll = long long int;

/*===================== CONSTANT =====================*/

const ll BIG = 1e18 + 1;
const ll MOD = 1e9 + 7;
const int m = 998244353;

/*============== FUNCTION INITIALIZATION =============*/

void solve();

/*================ IMPORTANT FUNCTION ================*/

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
            if (x != middle);
        }
        else
        {
            right = middle;
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

int gcd(int a, int b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*===================== SOLUTION =====================*/

vector<vector<int>> pref(2, vector<int>(100500, 0));
vector<vector<int>> a(2, vector<int>(100500, 0));

void initPref(int x, int size)
{
    if (a[x][0] % 2 == 0) pref[x][0] = 1;
    for (int i = 1; i < size; ++i)
    {
        pref[x][i] = pref[x][i-1];
        if (a[x][i] % 2 == 0) pref[x][i]++;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[0][i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[1][i];
    }
    initPref(0, n);
    initPref(1, n);
    for (int i = 0; i < q; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        if (y2 < y1) swap(y1, y2);
        if (x2 < x1) swap(x1, x2);
        ll ans = pref[1][y2] + pref[0][x2];
        if (x1 > 0) ans -= pref[0][x1 - 1];
        if (y1 > 0) ans -= pref[1][y1 - 1];
        if (ans == (x2 - x1 + 1) + (y2 - y1 + 1) || ans == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
        //cout << ans << '\n';
    }
    
}
 
/* ==================== KOTRETAN ===================== *\

5 4
2 3 4 3 3
1
2
3
10

11 (12) 13 14 (15) (16) 17 (18) 19 20 (21) 22 23
*/