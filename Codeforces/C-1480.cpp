#include <bits/stdc++.h>
#include <chrono>
/*
** Author: wkwkwill (Willy I. K.)
** 2021/02/07
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
    /*
    cin.tie(NULL);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(10);
    */
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

const int maxN = 100005;
vector<int> a(maxN);

void search(int l, int r, int vl, int vr)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    int vm; 
    cout << "? " << mid << '\n';
    cin >> vm;
    a[mid] = vm;
    cout.flush();
    if (r - l == 2)
    {
        if (vm < min(vl, vr))
        {
            cout << "! " << l+1 << '\n';
            cout.flush();
            return;
        }
    }
    if (vm > min(vl, vr)) return;
    else
    {
        search(l, (l+r)/2, vl, vm);
        search((l+r)/2, r, vm, vr);
    }
}

void solve()
{
    int n;
    cin >> n;
    int vl, vr, vm;
    cout << "? 1" << '\n';
    cin >> vl;
    a[1] = vl;
    cout.flush();
    cout << "? " << n << '\n';
    cin >> vr;
    a[n];
    cout.flush();
    cout << "? " << (n+1)/2 << '\n';
    cin >> vm;
    a[(n+1)/2] = vm;
    cout.flush();
    int mid = n/2;
    search(1, mid, vl, vm);
    search(mid, n, vm, vr);
}
 
/* ==================== KOTRETAN ===================== *\


8 6 2 3 4 9 1 5 7 10

100000
50000
25000
12500
6750
3300
1600
800
400
200
100
50
25
12
6
3

*/