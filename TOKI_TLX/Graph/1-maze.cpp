#include <bits/stdc++.h>

/*
by: wkwkwill
date: 2020/07/26
*/
using namespace std;

using ll = long long int;

int searchPath(pair<int, int> start, pair<int, int> finish, vector<vector<int>>& maze)
{
    int totalJarak = INT32_MAX - 1;
    queue<pair<int, int>> path;
    map<pair<int, int>, int> jarak;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size()));
    for (auto &n : visited) fill(n.begin(), n.end(), false);
    jarak[start] = 0;
    path.push(start);
    while(!path.empty())
    {
        //cout << 't';
        pair<int, int> cur = path.front();
        pair<int, int> temp;
        if (cur.first == 0 || cur.first == maze.size()-1 || cur.second == 0 || cur.second == maze[0].size()-1)
        {
            if (maze[cur.first][cur.second] == 0)
            {
                totalJarak = jarak[cur];
                break;
            }
        }
        visited[cur.first][cur.second] = true;
        if (cur.first > 0 && cur.second != 0 && cur.second != maze[0].size()-1)
            if (!visited[cur.first-1][cur.second] && maze[cur.first-1][cur.second] == 0) 
            {
                temp = make_pair(cur.first-1, cur.second);
                path.push(temp);
                jarak[temp] = jarak[cur] + 1;
            }
        if (cur.first < maze.size()-1 && cur.second != 0 && cur.second != maze[0].size()-1)
            if (!visited[cur.first+1][cur.second] && maze[cur.first+1][cur.second] == 0)
            {
                temp = make_pair(cur.first+1, cur.second);
                path.push(temp);
                jarak[temp] = jarak[cur] + 1;
            }
        if (cur.second > 0 && cur.first != 0 && cur.first != maze.size()-1)
            if (!visited[cur.first][cur.second-1] && maze[cur.first][cur.second-1] == 0) 
            {
                temp = make_pair(cur.first, cur.second-1);
                path.push(temp);
                jarak[temp] = jarak[cur] + 1;
            }
        if (cur.second < maze[0].size()-1 && cur.first != 0 && cur.first != maze.size()-1)
            if (!visited[cur.first][cur.second+1] && maze[cur.first][cur.second+1] == 0) 
            {
                temp = make_pair(cur.first, cur.second+1);
                path.push(temp);
                jarak[temp] = jarak[cur] + 1;
            }
        path.pop();
    }

    return totalJarak + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }
    cin >> a >> b;
    pair<int, int> start = make_pair(a-1, b-1);
    vector<pair<int, int>> keluar;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 || i == n-1 || j == 0 || j == m-1)
            {
                if (maze[i][j] == 0) keluar.push_back(make_pair(i, j));
            }
        }
    }
    //for (pair<int, int> n : keluar) cout << n.first << ", " << n.second << '\n';
    int ans = INT32_MAX;
    //cout << finish.first << ' ' << finish.second << '\n';
    ans = searchPath(start, keluar[0], maze);

    cout << ans << '\n';
}

/*
-1 -1  0 -1 -1
-1  0  0  0  0
-1 -1 -1  0 -1
-1  0  0 -1  0
-1 -1 -1  0 -1
*/