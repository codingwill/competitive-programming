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

map<ll, int> variety;
vector<int> possible;
vector<int> dp(250005, 0);
vector<ll> a(505);

const ll maks = 1e12;

ll countVariety(ll x, ll y)
{
    if (x == y) return maks / x - 1;
    ll fpb = gcd(x, y);
    ll kpk = (x * y) / fpb;
    ll sp = max((kpk + 1), (x + y)); //starting point
    ll bb = x + y - 1; //batas bawah
    ll ans = (maks / fpb) - ((sp-1) / fpb);
    ans += max(0LL, (sp-2) - bb);
    ans -= max(0LL, ((sp-2) / x) - (bb / x));
    ans -= max(0LL, ((sp-2) / y) - (bb / y));
    return ans;
}

void initDP(int x)
{
    int n = possible.size();
    int maksSum = x;
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = x; j >= possible[i]; j--)
        {
            dp[j] += dp[j - possible[i]];
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i+1; j < n; ++j)
        {
            ll count = countVariety(a[i], a[j]);
            cout << "(" << i + 1 << ", "  << j + 1 << ") = " << count << '\n';
            variety[count]++;
        }
    }
    for (auto &i : variety)
    {
        possible.push_back(i.second);
        cout << i.first << ' ' << i.second << '\n';
    }
    initDP(n * (n-1) / 2);
    for (int i = 0; i < q; ++i)
    {
        int query;
        cin >> query;
        dp[query] > 0 ? cout << "YES\n" : cout << "NO\n";
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