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
        int a, b;
        cin >> a >> b;
        int n = a + b;
        string s;
        cin >> s;
        vector<int> cnt(2, 0);
        cnt[0] = a;
        cnt[1] = b;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0') cnt[0]--;
            else if (s[i] == '1') cnt[1]--;
        }
        bool possible = true;
        for (int i = 0; i < n/2; ++i)
        {
            if (s[i] == '?' && s[(n-1)-i] == '?')
            {
                if (cnt[0] >= 2)
                {
                    s[i] = '0';
                    s[(n-1)-i] = '0';
                    cnt[0] -= 2;
                }
                else
                {
                    s[i] = '1';
                    s[(n-1)-i] = '1';
                    cnt[1] -= 2;
                }
            }
        }
        for (int i = 0; i < n/2; ++i)
        {
            if (s[i] == '?')
            {
                s[i] = s[(n-1)-i];
                cnt[s[(n-1)-i]-'0']--;
            }
        }
        for (int i = n-1; i >= n - (n/2); --i)
        {
            if (s[i] == '?')
            {
                s[i] = s[(n-1)-i];
                cnt[s[(n-1)-i]-'0']--;
            }
        }
    
        if (n % 2 == 1)
        {
            if (s[n/2] == '?')
            {
                if (cnt[0] > cnt[1])
                {
                    s[n/2] = '0';
                    cnt[0]--;
                }
                else if (cnt[1] > cnt[0])
                {
                    s[n/2] = '1';
                    cnt[1]--;
                }
            }
        }
        //cout << cnt[0] << ' ' << cnt[1] << '\n';
        if (cnt[0] < 0 || cnt[1] < 0) possible = false;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0') a--;
            if (s[i] == '1') b--;
        }
        //cout << s2 << '\n';
        if (s == s2 && a == 0 && b == 0)
        {
            cout << s << '\n';
        }
        else
        {
            cout << -1 << '\n';
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