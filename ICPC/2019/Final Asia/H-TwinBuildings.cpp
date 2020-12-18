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

bool MySortFirst(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

bool MySortSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first * a.second == b.first * b.second) return a.second> b.second;
    return a.first * a.second > b.first * b.second;
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

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    ll satu = -1;
    ll dua = -1;
    bool koma = false;
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[i] = make_pair(x, y);
        satu = max(satu, x * y);
    }
    if (satu % 2 == 1) koma = true;
    satu /= 2;
    sort(a.begin(), a.end(), MySortFirst);
    //for (auto &i : a) cout << i.first << ' ' << i.second << '\n';
    ll maksLebar = a[0].second;
    for (int i = 1; i < n; ++i)
    {
        dua = max(dua, a[i].first * min(a[i].second, maksLebar));
        maksLebar = max(maksLebar, a[i].second);
    }
    cout << max(satu, dua);
    if (dua > satu) koma = false;
    if (koma) cout << ".5\n";
    else cout <<".0\n";
    
}
/* ==================== KOTRETAN ===================== *\

3
6 6
3 10
2 10
18.0 (HARUSNYA 20.0)

5
1 7
6 5
3 22
4 11
8 15

5
3 5
6 7
2 3
4 9
5 5

4
25 6
70 2 
8 40
2 9
160.0
*/