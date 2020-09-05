#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

bool traversal(vector<vector<ll>>& adj, vector<ll> p, vector<ll> h)
{
    queue<ll> q;
    q.push(1);
    vector<bool> visited(adj.size());
    fill(visited.begin(), visited.end(), false);
    visited[1] = true;
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        if (cur != 1)
        {
            
        }
        for (int i = 0; i < adj[cur].size(); ++i)
        {
            if (!visited[adj[cur][i]])
            {
                q.push(adj[cur][i]);
                visited[cur] = true;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> p, h;
        vector<vector<ll>> adj(200600);
        for (int i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            p.push_back(input);
        }
        for (int i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            h.push_back(input);
        }
        for (int i = 0; i < n-1; ++i)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool possible = traversal(adj, p, h);
        possible ? cout << "YES\n" : cout << "NO\n";
    }

}