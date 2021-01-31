#include <bits/stdc++.h>
//#include <chrono>
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
 
/*================== DRIVER FUNCTION =================*/
 
int main()
{
    //input output optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
 
 
int n;

bool traverse(vector<int> arr, int x, int initSum)
{
    int N = n * 2;
    map<int, int> cnt;
    vector<pair<int, int>> ans;
    for (int i = 0; i < arr.size(); ++i)
    {
        cnt[arr[i]]++;
    }
    //cout << cnt[3] << '\n';
    cnt[x]--;
    cnt[initSum - x]--;
    ans.push_back(make_pair(x, initSum - x));
    int total = 1;
    for (int i = N-2; i >= 0; --i)
    {
        if (cnt[arr[i]] > 0)
        {
            if (cnt[x - arr[i]] > 0)
            {
                cnt[x - arr[i]]--; 
                cnt[arr[i]]--;
                total++;
                ans.push_back(make_pair(x - arr[i], arr[i]));
                x = arr[i];
            }
            else return false;
        }
    }
    if (total == n)
    {
        cout << "YES\n" << initSum << '\n';
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
        return true;
    }
    else return false;
}
 
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int N = n * 2;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        bool found = false;
        for (int i = N - 2; i >= 0; --i)
        {
            int x = arr[N-1];
            int initSum = x + arr[i];
            if (traverse(arr, x, initSum)) 
            {
                found = true;
                break;
            }
        }
        if (!found) cout << "NO\n";
    }
}
 
/* ==================== KOTRETAN ===================== *\
 
1
5
1 2 3 4 5 6 7 14 3 11
 
*/