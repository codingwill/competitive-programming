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

const int N = 100005;
int n;
vector<vector<ll>> bit(2, vector<ll>(N, 0));
//vector<ll> fenwick(N, 0);


void add(vector<ll> &arr, ll i, ll x)
{
    while (i <= n)
    {
        arr[i] = (arr[i] + x) % 2;
        i += i & -i;
        //cout << i << '\n';
    }
}

void range_add(ll l,ll r, ll x)
{
    add(bit[0], l, x);
    add(bit[0], (r + 1), -x);
    add(bit[1], l, x * (l-1));
    add(bit[1], (r + 1), -x * r);
}

ll sum(vector<ll> &arr, ll i)
{
    ll total = 0;
    while (i > 0)
    {
        total += arr[i];
        i -= i & -i;
    }
    return total;
}

ll prefix_sum(ll i)
{
    return sum(bit[0], i)*i -  sum(bit[1], i);
}

ll range_sum(ll l, ll r)
{
    return prefix_sum(r) - prefix_sum(l-1);
}

void solve()
{
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        int j = i + 1;
        if (s[i] == 'A')
        {
            
        }
        else
        {
            range_add(j, j, 1);
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll l, r;
            cin >> l >> r;
            range_add(l, r, 1);
        }
        else
        {
            ll l, r, a, b;
            cin >> l >> r >> a >> b;
            ll total = r - l + 1;
            ll countB = range_sum(l, r);
            ll countA = total - countB;
            cout << countA << ' ' << countB << '\n';
            //for (int i = 0; i < n; ++i) cout << bit[0][i] << ' ';
            //cout << '\n';
            cout << a + (countA * b) << ' ' << b + (countB * a) << '\n';
        }
        
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