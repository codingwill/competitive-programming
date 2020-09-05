#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
*/
using namespace std;
using ll = long long int;

int visited[200005];

int BFS(vector<vector<int>>& adj, vector<int>& cat, int maksKucing)
{
    queue<int> qNode;
    map<int, int> countKucing;
    qNode.push(1);
    visited[1] = true;
    if (cat[1]) countKucing[1] = 1;
    else countKucing[1] = 0;
    int countResto = 0;
    while (!qNode.empty())
    {
        int curNode = qNode.front();
        //cout << countKucing[curNode] << '\n';
        qNode.pop();
        if (countKucing[curNode] > maksKucing) continue;
        if (adj[curNode].size() == 1 && curNode != 1)
            countResto++;
        for (int i = 0; i < adj[curNode].size(); ++i)
        {
            if (cat[adj[curNode][i]] == 1) 
                countKucing[adj[curNode][i]] = countKucing[curNode] + 1;
            else
                countKucing[adj[curNode][i]] = 0;
            if (!visited[adj[curNode][i]])
            {
                qNode.push(adj[curNode][i]);
                visited[adj[curNode][i]] = true;
            }
        }
    }
    return countResto;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> cat(n+1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> cat[i+1];
    }
    for (int i = 0; i < n-1; ++i)
    {
        int mom, kid;
        cin >> mom >> kid;
        adj[mom].push_back(kid);
        adj[kid].push_back(mom);
    }
    cout << BFS(adj, cat, m) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
