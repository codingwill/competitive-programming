#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/12/05
*/
using namespace std;
using ll = long long int;

/*===================== CONSTANT =====================*/

const ll BIG = 1e18 + 1;
const ll MOD = 1e9 + 7;
const int m = 998244353;

/*============== FUNCTION INITIALIZATION =============*/

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

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

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}


/* SEGMENT TREE (BUKAN BASE CODE, MODIF DULU SEBELUM DIPAKE)

void segmentTree(int i, int left, int right)
{
    if (left == right)
    {
        tree[i] = 0;
    }
    else
    {
        int mid = (left + right) / 2;
        segmentTree(i*2, left, mid);
        segmentTree(i*2 + 1, mid + 1, right);
        tree[i] = 0;
    }
}

void update(int i, int left, int right, int queryLeft, int queryRight, int winner)
{
    if (queryLeft > queryRight) return;
    if (!alive[i]) return;
    if (left == right)
    {
        if (left == winner) return;
        tree[left] = winner;
        alive[i] = false;
        //cout << left << '\n';
    }
    else
    {
        int mid = (left + right) / 2;
        update(i*2, left, mid, queryLeft, min(queryRight, mid), winner);
        update(i*2 + 1, mid + 1, right, max(queryLeft, mid + 1), queryRight, winner);
        alive[i] = alive[i*2] || alive[i*2 + 1];
    }
}

/* BROKEN GET LOL
int get(int i, int left, int right, int pos)
{
    if (left == right) return tree[i];
    if (pos > right || pos < left) return 0;
    if (left > right) return 0;
    int mid = (left + right) / 2;
    get(i*2, left, mid, pos);
    get(i*2 + 1, mid + 1, right, pos);
}
*/


/*===================== SOLUTION =====================*/

vector<int> primelist = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
vector<bool> prime(31, false);

void solve()
{
    ll ans = 1;
    for (int i = 0; i < primelist.size(); ++i)
    {
        prime[primelist[i]] = true;
        ans *= primelist[i];
    }
    ll n;
    cin >> n;
    for (int i = 2; i <= 29; ++i)
    {
        if (!prime[i])
        {
            if (i == 4 || i == 9 || i == 16 || i == 25)
            {
                ans *= sqrt(i);
            }
            else if (i == 27)
            {
                ans *= 3;
            }
            else if (i == 8)
            {
                ans *= 2;
            }
        }
    }
    cout << ans + 1<< '\n';
}
 
/* ==================== KOTRETAN ===================== *\

2 (3) 5 (7) 11 (13) 17 (19) 23 29

2 3
3 7
4 13
5 61
6 361
*/