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

vector<ll> pref(200050, 0);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (k == 1) cout << 0 << '\n';
    else if (k == 2) cout << abs(a[0] - a[n-1]) << '\n';
    else
    {
        vector<ll> b;
        int x = 0, y = n-1;
        for (int i = 0; i < k; ++i)
        {
            if (i % 2 == 0) 
            {
                b.push_back(a[x]);
                x++;
            }
            else
            {
                b.push_back(a[y]);
                y--;
            }
            
        }
        sort(b.begin(), b.end());
        pref[0] = b[0];
        for (int i = 1; i < k-1; ++i)
        {
            pref[i] = pref[i-1] + b[i];
        }
        ll ans = abs((b[k-1] * (k-1)) - pref[k-2]);
        for (int i = k-2; i >= 1; --i)
        {
            ans += abs((b[i] * i) - pref[i-1]);
        }
        cout << ans << '\n';
    }
    

}
 
/* ==================== KOTRETAN ===================== *\

7 2 1 = 5 + 6 + 1
7 5 1 = 2 + 6 + 4
7 6 1 = 1 + 6 + 5
7 3 1 = 4 + 6 + 2

8 1 4 = 7 + 4 + 3 = 14
8 1 6 = 7 + 2 + 5 = 14

10 6 1 = 4 + 9 + 5 = 18
10 9 1 = 1 + 9 + 8 = 18

10 1 3 6 7 = 9 + 7 + 4 + 3 + 2 + 5 + 6 + 3 + 4 + 1 = 44
10 1 3 9 6 = 1 + 13 + 2 + 9
1 3 6 9 10 = 21 + 17 + 8 + 2 = 48
*/