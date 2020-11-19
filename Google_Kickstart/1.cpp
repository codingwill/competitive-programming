#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
vector<vector<bool>> dp(50, vector<bool>());
vector<ll> fibo(46);

void solve();
 
ll fastpow(ll x, ll y, ll n = BIG) 
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    solve();
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
 
vector<string> res;

void check(const vector<ll>& v) 
{
    res.push_back("");
    bool start = false;
    int p = 0;
    if (v.size() > 0)
    {
        for (int i = fibo.size()-1; i >= 0; --i)
        {
            if (fibo[i] == v[p])
            {
                start = true;
            }
            if (start)
            {
                if (fibo[i] == v[p]) 
                {
                    res[res.size()-1].push_back('1');
                    if (p < v.size()-1) p++;
                }
                else res[res.size()-1].push_back('0');
            }
        }
    }
    

}

bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void toBinary(vector<ll> a, int i, int sum, vector<ll>& p) 
{ 
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        p.push_back(a[i]); 
        check(p); 
        return; 
    } 
    if (i == 0 && sum == 0) 
    { 
        check(p); 
        return; 
    } 
  
    if (dp[i-1][sum]) 
    { 
        vector<ll> b = p; 
        toBinary(a, i-1, sum, b); 
    } 
  
    if (sum >= a[i] && dp[i-1][sum-a[i]]) 
    { 
        p.push_back(a[i]); 
        toBinary(a, i-1, sum-a[i], p); 
    } 
} 

void traverse(vector<ll> a, int n, int sum) 
{ 
    if (n == 0 || sum < 0) 
       return; 
  
    dp = new bool*[n]; 
    for (int i=0; i<n; ++i) 
    { 
        dp[i] = new bool[sum + 1]; 
        dp[i][0] = true; 
    } 
  
    if (a[0] <= sum) 
       dp[0][a[0]] = true; 
  
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < sum + 1; ++j) 
        {
            dp[i][j] = (a[i] <= j) ? dp[i-1][j] || dp[i-1][j-a[i]] : dp[i - 1][j]; 
        }
    }
    if (!dp[n-1][sum]) 
    { 
        return; 
    } 
    vector<ll> p; 
    toBinary(a, n-1, sum, p); 
} 

bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}

void solve()
{
    int t;
    cin >> t;
    fibo[0] = 1;
    fibo[1] = 2;
    for (int i = 2; i < fibo.size(); ++i)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    vector<string> ans;
    for (int i = 0; i < fibo.size(); ++i)
    {
        string s;
        ll temp = fibo[i];
        while (temp != 0)
        {
            char c = '0' + temp % 2;
            s.push_back(c);
            temp /= 2;
        }
        reverse(s.begin(), s.end());
        ans.push_back(s);
    }
    while (t--)
    {
        res.clear();
        int input;
        cin >> input;
        traverse(fibo, fibo.size(), input); 
        if (res.size() > 0) sort(res.begin(), res.end(), stringSort);
        //cout << res.size() << '\n';
        //for (auto n : res) cout << n << ' ';
        if (res.size() > 0) cout << res[0] << '\n';
        else cout << 0 << '\n';
    }

}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 
*/