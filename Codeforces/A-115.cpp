#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std
//AUTHOR'S NAME
Willy Indrayana Komara;

using ll = long long int;

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