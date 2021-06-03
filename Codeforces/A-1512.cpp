#include <bits/stdc++.h>
#include <chrono>
/*
** Author: codingwill (Willy I. K.)
** 2021/04/04
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
    //input output optimization
    
    ios_base::sync_with_stdio(false);
    
    cin.tie(NULL);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(10);
    
    //debug time
    /*
    auto start = chrono::high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    */

    //solve function
    solve();
    
    //debug time
    /*
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    ofstream file;
    file.open("time.txt");
    file << duration.count() << " ms.";
    file.close();
    */
    return 0;
}
  
ll factorial(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return factorial(n) / ((factorial(r) * factorial(n - r)) % MOD); 
} 

bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
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

int gcd(ll a, ll b) 
{
    while (b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*===================== SOLUTION =====================*/
//fungsi pembagian dengan membulatkan ke atas (ceil)
ll bagi(ll a, ll b)
{
    if (a % b == 0) return a / b;
    return a / b + 1;
}

int countElement(vector<bool> a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i]) ans++;
    }
    return ans;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(101, 0);
        vector<int> b(n);
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            a[input]++;
            b[i] = input;
        }
        int ans;
        for (int i = 1; i <= 100; ++i)
        {
            if (a[i] == 1) ans = i;
        }
        for (int i = 0; i < n; ++i)
        {
            if (b[i] == ans)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}
 
/* ==================== KOTRETAN ===================== *\
6 3
8 9 4 17 11 5

0 = 0
1 = 1
2 = 0
3 = 3
4 = 1
5 = 1
6 = 0
7 = 0
8 = 1
9 = 0

4 6
1 2 7 4

4 6
17 4 58 7
406
476

4 = 1
7 = 2
8 = 1

0

*/