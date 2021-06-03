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
    int n, q;
    cin >> n >> q;
    vector<int> color(51, 0);
    vector<int> input(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    for (int i = n-1; i >= 0; --i)
    {
        color[input[i]] = i + 1;
    }
    for (int i = 0; i < q; ++i)
    {
        int query;
        cin >> query;
        cout << color[query] << ' ';
        for (int j = 1; j < color.size(); ++j)
        {
            if (color[j] < color[query])
            {
                color[j]++;
            }
        }
        color[query] = 1;
    }
}
 
/* ==================== KOTRETAN ===================== *\
7 5
2 1 1 4 3 3 1
3 2 1 1 4

2 1(2) 4 3(2)

1 = 2
2 = 1
3 = 5
4 = 4

3

1 = 3
2 = 2
3 = 1
4 = 5

2

1 = 3
2 = 1
3 = 2
4 = 5

1

1 = 1
2 = 2
3 = 3
4 = 5

1 = 2 3 7
2 = 1
3 = 5 6
4 = 4
*/
