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

const int maxN = 100005;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bitset<maxN> ada(false);
        vector<int> a(n), b(n);
        int lastColor;
        vector<int> c(m);
        map<int, int> beda;
        vector<vector<int>> index(maxN), index2(maxN);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }  
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
            ada[b[i]] = true;
            index[b[i]].push_back(i+1);
            if (a[i] != b[i])
            {
                beda[b[i]]++;
                count++;
                index2[b[i]].push_back(i+1);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            cin >> c[i];
        }
        if (a == b)
        {
            if (!ada[c[m-1]])
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                int ans = index[c[m-1]].back();
                for (int i = 0; i < m; ++i)
                {
                    cout << ans << ' ';
                }
                cout << '\n';
            }
        }
        else
        {
            int num = -1;
            vector<int> ans;
            int count1 = 0;
            for (int i = m-1; i >= 0; --i)
            {
                if (beda[c[i]] == 0)
                {
                    ans.push_back(num);
                }
                else 
                {
                    beda[c[i]]--;
                    num = index2[c[i]].back();
                    ans.push_back(num);
                    index2[c[i]].pop_back();
                    count1++;
                }
            }
            if (count == count1)
            {   
                cout << "YES\n";
                for (int i = m-1; i >= 0; --i)
                {
                    cout << ans[i] << ' ';
                }
                cout << '\n';
            }
            else cout << "NO\n";
        }
        
    }
}
 
/* ==================== KOTRETAN ===================== *\

if a == b, tinggal cari apakah ada bi == c[last]


*/