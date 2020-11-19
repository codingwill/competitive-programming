#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

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

vector<pair<string, int>> ans;
vector<vector<vector<ll>>> dp(35, vector<vector<ll>>(35, vector<ll>(70 * 250, 0)));

/*

void dfs(vector<vector<int>> &a, int i, int j, int count, string path)
{
    if (i == a.size()-1 && j == a[0].size()-1)
    {
        ans.push_back(make_pair(path, count));
        return;
    }
    if (i < a.size() - 1) 
    {
        dfs(a, i+1, j, count + a[i+1][j], path + "D");
    }
    if (j < a[0].size() - 1) 
    {
        dfs(a, i, j+1, count + a[i][j+1], path + "R");
    }  
}

/*
void dfs(vector<vector<int>> &a, int i, int j, int count, string path)
{
    stack<pair<int, int>> q;
    q.push(make_pair(i+1, j));
    q.push(make_pair(i, j+1));
    while (!q.empty())
    {
        
        pair<int, int> node = q.top();
        q.pop();
        
        int y = node.first;
        int x = node.second;
        count += a[y][x];
        
        if (x == a[0].size()-1 && y == a.size()-1)
        {
            ans.push_back(make_pair(path, count));
        }
        if (y < a.size()-1)
        {
            q.push(make_pair(y+1, x));
            path += "D";
        }
        if (x < a[0].size()-1)
        {
            q.push(make_pair(y, x+1));
            path += "R";
        }
    }
}
*/
int r, c;
void DP(vector<vector<int>> &a, ll total)
{
    dp[0][0][a[0][0]] = 1;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            dp[i][j][0] = 0;
        }
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (i == 0 && j == 0) continue;
            for (int k = 1; k <= total; ++k)
            {
                if (a[i][j] > k) dp[i][j][k] = 0;
                if (a[i][j] <= k) 
                {
                    int count = 0;
                    if (i > 0) count += dp[i-1][j][k - a[i][j]];
                    if (j > 0) count += dp[i][j-1][k - a[i][j]];
                    dp[i][j][k] = count;
                }
            }
        }
    }
}

void backtrack(vector<vector<int>> &a, int i, int j, int total, ll k)
{
    if (i == r-1 && j == c-1) return;
    ll down;
    if (i+1 >= r || j+1 >= c || total - a[i][j] < 0) down = 0;
    else if (i == r-1 && j == c-1) down = (total - a[i][j] == a[i][j]);
    else down = dp[i+1][j][total - a[i][j]];
    if (k <= down)
    {
        printf("D");
        backtrack(a, i + 1, j, total - a[i][j], k);
    }    
    else
    {
        printf("R");
        backtrack(a, i, j + 1, total - a[i][j], k - down);
    }
}

void solve()
{
    ll k;
    cin >> r >> c >> k;
    vector<vector<int>> a(r+5, vector<int>(c+5, 0));    
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> a[i][j];
        }
    }    
    int count = a[0][0];
    DP(a, 59 * 200 + 50);
    for (int i = 0; i < 20; ++i)
    {
        cout << dp[1][0][i] << ' ';
    }
    
    for (int i = 59 * 200 + 5; i >= 0; --i)
    {
        ll temp = dp[r-1][c-1][i];
        if (k <= temp)
        {
            backtrack(a, 0, 0, i, k);
            break;
        }
        else
        {
            k -= temp;
        }
        
    }
    
    /*
    for (auto &i : ans)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
    */
}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 
*/