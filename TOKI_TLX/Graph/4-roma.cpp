#include <bits/stdc++.h>

/*
by: wkwkwill
date: 2020/07/29
*/
using namespace std;

using ll = long long int;

vector<bool> utamaVisited(200000);
vector<bool> tolVisited(200000);

struct Node
{
    int name, pathUtama, pathTol;
}

int shortestPath(vector<vector<int>>& graph, int start, int finish)
{
    queue<Node> node;
    Node cur = {start, 0, 0};
    node.push(cur);
    while (!node.empty())
    {
        cur = node.front();
        node.pop();
        for (int i = 0; i < graph[cur.name].size(); ++i)
        {
            if (!utamaVisited[graph[cur.name][i]])
            {
                Node temp = {graph[cur.name][i], cur.pathUtama + 1, cur.pathTol + 1};
                node.push(temp);
            }
        }
    }
}

int main()
{
    int n, l, t, start, finish;
    cin >> n >> l >> t >> start >> finish;
    vector<vector<int>> utama(n+10);
    vector<vector<int>> tol(t+10);
    for (int i = 0; i < l; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        utama[node1].push_back(node2);
        utama[node2].push_back(node1);
    }
    for (int i = 0; i < t; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        tol[node1].push_back(node2);
        tol[node2].push_back(node1);
    }
}