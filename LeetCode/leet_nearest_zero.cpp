#include <bits/stdc++.h>
/*
by: wkwkwill
date: 2020/07/08
*/

using namespace std;

class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = BFS(matrix, make_pair(i, j));
                }
            }
        }
    }

    int BFS(vector<vector<int>>& matrix, pair<int, int> node)
    {
        queue<pair<int, int>> nodeQueue;
        map<pair<int, int>, int> nodeLevel;
        nodeQueue.push(node);
        nodeLevel[node] = 0;
        int dist = 0;
        bool foundZero = false;
        while (!nodeQueue.empty())
        {
            pair<int, int> temp = nodeQueue.front();
            if (matrix[temp.first][temp.second] == 0)
            {
                dist = nodeLevel[make_pair(temp.first, temp.second)];
                foundZero = true;
                break;
            }
            else
            {
                if (temp.first > 0 )
                {
                    nodeQueue.push(make_pair(temp.first-1, temp.second)); //atas
                    nodeLevel[make_pair(temp.first-1, temp.second)] = nodeLevel[temp] + 1;
                }
                if (temp.second > 0)
                {
                    nodeQueue.push(make_pair(temp.first, temp.second-1)); //kiri
                    nodeLevel[make_pair(temp.first-1, temp.second)] = nodeLevel[temp] + 1;
                }
                if (temp.first < matrix.size()-1) 
                {
                    nodeQueue.push(make_pair(temp.first+1, temp.second)); //bawah
                    nodeLevel[make_pair(temp.first-1, temp.second)] = nodeLevel[temp] + 1;
                }
                if (temp.first < matrix[0].size()-1) 
                {
                    nodeQueue.push(make_pair(temp.first, temp.second+1)); //kanan
                    nodeLevel[make_pair(temp.first-1, temp.second)] = nodeLevel[temp] + 1;
                }
                nodeQueue.pop();
            }
        }
        return dist;
    }

};

int main()
{

}