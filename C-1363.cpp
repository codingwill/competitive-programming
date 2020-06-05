#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/05/31
*/
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> adj[n+1];
        vector<int> visited(n+1);
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < n-1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (adj[x].size() == 1) 
        {
            cout << "Ayush" << '\n';
            continue;
        }
        queue<int> q;
        q.push(x);
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            for (int i = 0; i < adj[node].size(); ++i)
            {
                if (visited[adj[node][i]]) continue;
                q.push(adj[node][i]);
                count++;
                visited[adj[node][i]] = true;
            }
            q.pop();
        }
        cout << count - 1 << endl;
        cout << ((count-1) % 2 == 0 ? "Ashish" : "Ayush") << '\n';
        visited.clear();
    }
}