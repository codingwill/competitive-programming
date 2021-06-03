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
        res = ((res * i) % MOD + MOD) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return factorial(n) / (((factorial(r) * factorial(n - r)) % MOD + MOD) % MOD); 
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
    int total = t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> kiri(n, 0), kanan(n, 0);
        vector<int> a(n), beda(n, 0);
        int maks = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int diff = a[1] - a[0];
        int len = 2;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] - a[i-1] != diff)
            {
                len = 2;
                diff =  a[i] - a[i-1];
            }
            beda[i] = diff;
            kiri[i] = len;
            len++;
        }
        for (int i = n-2; i >= 0; --i)
        {
            if (a[i] - a[i+1] != diff)
            {
                len = 2;
                diff =  a[i] - a[i+1];
            }
            kanan[i] = len;
            if (kanan[i] > kiri[i]) beda[i] = diff * -1;
            len++;
        }
        for (int i : kiri)
        {
            maks = max(maks, i);
        }
        int ans = 0;
        for (int i = 1; i < n-1; ++i)
        {
            if (abs(a[i-1] - a[i+1]) % 2 == 0)
            {
                if (a[i] != (a[i-1] + a[i+1]) / 2)
                {
                    if (beda[i-1] == beda[i+1])
                    {
                        ans = max(max(kiri[i-1], kanan[i-1]) + max(kiri[i+1], kanan[i+1]) + 1, ans);
                        
                    }
                    else
                    {
                        ans = max(max(max(kiri[i-1], kanan[i-1]) + 2, max(kiri[i+1], kanan[i+1]) + 2), ans);
                    }
                }
                
            }
            
        }
        if (beda[0] != beda[1]) maks = max(maks, max(kiri[1], kanan[1]) + 1);
        if (beda[n-1] != beda[n-2]) maks = max(maks, max(kiri[n-2], kanan[n-2]) + 1);
        maks++;
        if (maks > n) maks = n;
        cout << "Case #" << total - t << ": ";
        cout << max(ans, maks) << '\n';
    }
}


/* ==================== KOTRETAN ===================== *\
3
4
9 7 5 3
9
5 5 4 5 5 5 4 5 6
  2 2 2 2 3 2 2 3
2 2 2 3 2 2 3 2
2 2 2 3 2 3 3 2 3  

4
8 5 2 0

*/

