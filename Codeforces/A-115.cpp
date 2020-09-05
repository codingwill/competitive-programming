#include <bits/stdc++.h>

/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
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

bool sortPairFirst(pair<int, bool> &a, pair<int, bool> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

//BFS (Iterative)
int bfs(vector<vector<int>> adj, int a[])
{
    queue<int> q;
    vector<bool> vis(adj.size(), false);
    map<int, int> level;
    int ans = 1;
    for (int i = 1; i < adj.size(); ++i)
    {
        if (a[i] != -1) continue;
        q.push(i);
        level[i] = 1;
        while (!q.empty())
        {   
            int node = q.front();
            for (int j = 0; j < adj[node].size(); ++j)
            {
                if (vis[adj[node][j]]) continue;
                q.push(adj[node][j]);
                level[adj[node][j]] = level[node] + 1;
                ans = max(ans, level[adj[node][j]]);
                vis[adj[node][j]] = true;
            }
            q.pop();
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj;
    int a[n+1];
    adj.resize(n+1);
    for (int x = 0; x < n; ++x)
    {
        int node;
        cin >> node;
        a[x+1] = node;
        if (node == -1) continue;
        adj[node].push_back(x+1);
    }
    cout << bfs(adj, a) << '\n';
}
