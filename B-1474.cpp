#include <bits/stdc++.h>
#include <chrono>
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
    //input output optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

vector<bool> is_prime(300000+1, true);
vector<int> prime;
void sieve()
{
    prime.push_back(1);
    int n = 300000;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) 
    {
        if (is_prime[i] && (long long) i * i <= n) 
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < is_prime.size(); ++i)
    {
        if (is_prime[i]) prime.push_back(i);
    }
}

void solve()
{
    sieve();
    //cout << is_prime[6] << '\n';
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        int prev = 1;
        int total = 1;
        int ans = 1;
        for (int i = 1; i < prime.size(); ++i)
        {
            if (total == 3) break;
            if (abs(prev - prime[i]) >= d)
            {
                total++;
                ans *= prime[i]; 
                prev = prime[i];
                //cout << prime[i] << '\n';
            }
        }
        cout << ans << '\n';
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