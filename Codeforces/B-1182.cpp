#include <bits/stdc++.h>

/*
by: wkwkwill
date: 2020/08/05
*/
using namespace std;

using ll = long long int;

bool visited[505][505];
vector<vector<char>> a(505, vector<char>(505));

int bfs(vector<vector<char>> &a, pair<int, int> start)
{
    int countPlus = 0;
    bool possible = true;
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        visited[cur.first][cur.second] = true;
        //cout << cur.first << ' ' << cur.second << '\n';
        bool atas = false, kanan = false, bawah = false, kiri = false;
        q.pop();
        if (cur.first > 0)
        {
            if (a[cur.first - 1][cur.second] == '*')
            {
                if (!visited[cur.first - 1][cur.second]) q.push(make_pair(cur.first - 1, cur.second));
                atas = true;
            }
        }
        if (cur.first < a.size()-1)
        {
            if (a[cur.first + 1][cur.second] == '*')
            {
                if (!visited[cur.first + 1][cur.second]) q.push(make_pair(cur.first + 1, cur.second));
                bawah = true;
            }
        }
        if (cur.second > 0)
        {
            if (a[cur.first][cur.second - 1] == '*')
            {
                if (!visited[cur.first][cur.second - 1]) q.push(make_pair(cur.first, cur.second - 1));
                kiri = true;
            }
        }
        if (cur.second < a[0].size()-1)
        {
            if (a[cur.first][cur.second + 1] == '*')
            {
                if (!visited[cur.first][cur.second + 1]) q.push(make_pair(cur.first, cur.second + 1));
                kanan = true;
            }
        }
        if (atas && kanan && bawah && kiri) countPlus++;
        else if (atas && !kanan && !bawah && !kiri) continue;
        else if (!atas && kanan && !bawah && !kiri) continue;
        else if (!atas && !kanan && bawah && !kiri) continue;
        else if (!atas && !kanan && !bawah && kiri) continue;
        else if (atas && !kanan && bawah && !kiri) continue;
        else if (!atas && kanan && !bawah && kiri) continue;
        else possible = false;
    }
    if (possible && countPlus == 1) return 1;
    else return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> a[i][j];
        }
    }
    int countPlus = 0;
    int countGraph = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (a[i][j] == '*' && !visited[i][j])
            {
                //cout << i << ' ' << j << '\n';
                countPlus += bfs(a, make_pair(i, j));
                countGraph++;
            }
        }
    }
    //cout << countPlus << '\n';
    if (countPlus == 1 && countGraph == 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

/*
for (int i = 1; i < h-1; ++i)
    {
        for (int j = 1; j < w-1; ++j)
        {
            if (!visited[i][j] && a[i][j] == '*' && a[i-1][j] == '*' && a[i][j+1] == '*' && a[i+1][j] == '*' && a[i][j-1] == '*')
            {
                visited[i][j] = true;
                bool isPlus = true;
                int atas = i-1, kanan = j+1, bawah = i+1, kiri = j-1;
                while (atas >= 0)
                {
                    visited[atas][j] = true;
                    if (a[atas][j-1] == '*')
                    {
                        visited[atas][j-1] = true;
                        isPlus = false;
                        break;
                    }
                    if (a[atas][j+1] == '*')
                    {
                        visited[atas][j-1] = true;
                        isPlus = false;
                        break;
                    }
                    atas--;
                }
                while (kanan < w)
                {
                    visited[i][kanan] = true;
                    if (a[i-1][kanan] == '*')
                    {
                        visited[i-1][kanan] = true;
                        isPlus = false;
                        break;
                    }
                    if (a[i+1][kanan] == '*')
                    {
                        visited[i+1][kanan] = true;
                        isPlus = false;
                        break;
                    }
                    kanan++;
                }
            }
        }
    }
*/