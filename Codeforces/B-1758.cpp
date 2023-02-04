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
        if (y & 1)
            ans = (ans * x) % n;
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
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
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
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

bool stringSort(string &a, string &b)
{
    if (a.length() > b.length())
        return a.length() > b.length();
    return a > b;
}

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        // cout << middle << '\n';
        // if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle)
                ;
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

const int factor = 6;
int n;
const int banCharacters = 3;

void printIfEven(int m)
{
    for (int i = 0; i < m; ++i)
    {
        cout << i * factor + 1 << " " << i * factor + 5 << '\n';
    }
}

void printIfOdd(int m)
{
    for (int i = 0; i < m - 1; ++i)
    {
        cout << i * factor + 1 << " " << i * factor + 5 << '\n';
    }

    cout << banCharacters * n - 2 << " " << banCharacters * n - 1 << '\n';
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 != 0)
        {
            while (n--)
            {
                cout << 1 << ' ';
            }
        }
        else
        {
            while (n > 2)
            {
                cout << 2 << ' ';
                n--;
            }
            cout << "1 3";
        }

        cout << '\n';
    }
}

/* ==================== KOTRETAN ===================== *\

1
1 1 1
1 1 1 1 1

2 2 1 3
2 2 2 2 1 3
2 2 2 2 2 2 1 3
2 2 2 2 2 2 2 2 1 3

*/