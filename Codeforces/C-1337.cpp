#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
    if (get<2>(a) == get<2>(b)) return get<1>(a) > get<1>(b);
    return get<2>(a) < get<2>(b); 
}

int dist[200005];
bool visited[200005];
vector<int> adj[200005];
bool industry[200005];

void adjList(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int count)
{
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dist[adj[node][i]] += dist[node] + 1;
            dfs(adj[node][i], count);
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> nodeDist; //node, dist, adjacent nodes
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList(adj, u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        nodeDist.push_back(make_tuple(i, dist[i], adj[i].size()));
    }
    sort(nodeDist.begin(), nodeDist.end(), besarDulu);

    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        industry[get<0>(nodeDist[i])] = true;
        int minus = 0;
        for (int j = 0; j < adj[get<0>(nodeDist[i])].size(); j++)
        {
            if (industry[adj[get<0>(nodeDist[i])][j]]) 
            {
                minus++;
                //cout <<'t' << endl;
            }
        }
        ans += get<1>(nodeDist[i]) - minus;
    }
    cout << ans << '\n';
    
    return 0;
}

/*
(((h/2 + 10) / 2 + 10) / 2 + 10)
*/