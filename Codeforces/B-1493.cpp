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

void solve()
{
    int t;
    cin >> t;
    vector<bool> valid(101, 0);
    int x[] = {1, 2, 5, 8, 0};
    set<int> canMirror(x, x + 5);
    for (int i = 0; i < valid.size(); ++i)
    {
        if (canMirror.find(i % 10) != canMirror.end() && 
            canMirror.find(i / 10) != canMirror.end() && 
            canMirror.find(i / 100) != canMirror.end())
        {
            valid[i] = true;
        }
    }
    valid[100] = true;
    vector<int> mirror(10);
    mirror[0] = 0;
    mirror[1] = 1;
    mirror[2] = 5;
    mirror[5] = 2;
    mirror[8] = 8;
    /*
    for (int i = 0; i < valid.size(); ++i)
    {
        if (valid[i]) cout << i << '\n';
    }
    */
    while (t--)
    {
        int h, m;
        cin >> h >> m;
        string jam;
        cin >> jam;
        vector<int> format(2, 0);
        
        int p = 0;
        for (int i = 0; i < jam.size(); ++i)
        {
            if (jam[i] == ':')
            {
                p++;
            }
            else
            {
                format[p] *= 10;
                format[p] += jam[i] - '0';
            }
        }
        //cout << format[0] << ' ' << format[1] << '\n';

        int j = format[0];
        bool found = false;
        int debug = 0;
        while (true)
        {
            if (found) break;
            if (j >= h) j = 0;
            for (int i = (debug == 0 ? format[1] : 0); i < m; ++i)
            {
                string x = to_string(j % h);
                if (j / 10 == 0) x = "0" + x; 
                string y = to_string(i % m);
                if (i / 10 == 0) y = "0" + y;
                reverse(x.begin(), x.end());
                reverse(y.begin(), y.end());
                int hour = stoi(y);
                int minute = stoi(x);
                if (valid[hour] && valid[minute])
                {
                    for (int l = 0; l < x.size(); ++l)
                    {
                        x[l] = '0' + mirror[x[l] - '0'];
                    }
                    for (int l = 0; l < y.size(); ++l)
                    {
                        y[l] = '0' + mirror[y[l] - '0'];
                    }
                    hour = stoi(y);
                    minute = stoi(x);
                    //if (debug == 0) cout << hour << minute << '\n';
                    if (hour < h && minute < m)
                    {
                        int hLen = 2 - to_string(j).length();
                        int mLen = 2 - to_string(i).length();

                        for (int k = 0; k < hLen; ++k)
                            cout << 0;
                        cout << j << ":";
                        for (int k = 0; k < mLen; ++k)
                            cout << 0;
                        cout << i << '\n';
                        found = true;
                        break;
                    }
                }
            }
            j++;
            debug++;
        }
    }
}
 
/* ==================== KOTRETAN ===================== *\
01:00

05:02
50:20

3 1
2 3 4 5

3 2
1 3 4 5

3 3
1 4 5
2 4 5

3 4
1 2 5
2 3 5

3 5
1 2 
2 4
3 4

10 8
9 10 4 5 6 7 
1 2 3 9 10

10 9
10 5 6 7 8
*/