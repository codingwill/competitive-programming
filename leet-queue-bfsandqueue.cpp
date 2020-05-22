#include <bits/stdc++.h>

using namespace std;

/*
** Author: wkwkwill
** 22/05/2020 07:03 PM
*/

class Solution {
    
private:
    vector<char> node;
    vector<vector<int>> adj;
    int ans = 0;
    vector<int> visited;
    queue<int> q;

public:
    //breadth first search (recursive)
    void bfs(int i)
    {
        if (q.empty()) ++ans;
        if (!q.empty()) q.pop();
        if (adj[i].size() != 0)
        {
            for (int j = 0; j < adj[i].size(); ++j)
            {
                if (!visited[adj[i][j]])
                {
                    q.push(adj[i][j]);
                    visited[adj[i][j]] = true;
                }
            }
            if (!q.empty()) bfs(q.front());
        }
    }

    //graph construction
    void makeGraph(vector<vector<char>>& a)
    {
        int n = a[0].size();
        for (int i = 0; i < a.size(); ++i)
        {
            int index = i * n;
            for (int j = 0; j < a[i].size(); ++j)
            {
                node.push_back(a[i][j]);
                //up
                if (i > 0)
                {
                    if (a[i-1][j] == '1')
                    {
                        adj[index + j].push_back(index - n + j);
                    }
                }
                //right
                if (j < a[i].size()-1)
                {
                    if (a[i][j+1] == '1')
                    {
                        adj[index + j].push_back(index + j + 1);
                    }
                }
                //down
                if (i < a.size()-1)
                {
                    if (a[i+1][j] == '1')
                    {
                        adj[index + j].push_back(index + n + j);
                    }
                }
                //left
                if (j > 0)
                {
                    if (a[i][j-1] == '1')
                    {
                        adj[index + j].push_back(index + j - 1);
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return {};
        
        //variable initialization
        visited.resize(grid.size()*grid[0].size() + 5);
        adj.resize(grid.size()*grid[0].size() + 5);
        makeGraph(grid);
        
        //iterate all nodes
        for (int i = 0; i < node.size(); ++i)
        {
            if (visited[i]) continue;
            if (node[i] == '1')
            {
                visited[i] = true;
                bfs(i);
            }
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<vector<char>> input;
    int r, c;
    cout << "row    = "; cin >> r;
    cout << "column = "; cin >> c;
    input.resize(r);
    for (int i = 0; i < r; ++i)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < c; ++j)
        {
            input[i].push_back(temp[j]);
        }
    }
    cout << "The number of islands = " << sol.numIslands(input) << endl;
}