#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/04
*/
using namespace std;
using ll = long long int;

class Solution 
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        for (int i = 0; i < A.size(); ++i)
        {
            reverse(A[i].begin(), A[i].end());
            for (int j = 0; j < A[i].size(); ++j)
            {
                A[i][j] = (A[i][j] + 1) % 2;
            }
        }
        return A; 
    }
};