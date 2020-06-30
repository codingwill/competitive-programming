#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/30
*/

using namespace std;
using ll = long long int;

vector<pair<pair<pair<int, int>, int>, int>> suf;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        int leftRow = 0, leftCol = 0;
        int rightRow = n-1, rightCol = m-1;
        int leftLen = 0, rightLen = m-1;
        int leftLenRow = 0, rightLenRow = n-1;
        int zero = 0, one = 0;
        ll count = 0;
        int i = 0;
        while (true)
        {
            if ((leftRow == rightRow && leftCol == rightCol) || visited[leftRow][leftCol] || visited[rightRow][rightCol])
            {  
                break;
            }

            visited[leftRow][leftCol] = true;
            visited[rightRow][rightCol] = true;

            if (a[leftRow][leftCol] == 0) ++zero;
            else ++one;

            if (a[rightRow][rightCol] == 0) ++zero;
            else ++one;
            
            //left pointer
            if (leftRow == n-1 || leftCol == 0)
            {
                count += min(zero, one);
                if (leftLen < m-1) ++leftLen;
                else ++leftLenRow;
                leftRow = leftLenRow;
                leftCol = leftLen;
                zero = 0;
                one = 0;
                ++i;
            }
            else
            {
                ++leftRow;
                --leftCol;
            }
            
            //right pointer
            if (rightRow == 0 || rightCol == m-1)
            {
                if (rightLen > 0) --rightLen;
                else --rightLenRow;
                rightCol = rightLen;
                rightRow = rightLenRow;
                one = 0;
                zero = 0;
            }
            else
            {
                --rightRow;
                ++rightCol;
            }
        }
        a.clear();
        visited.clear();
        cout << count << '\n';
    }
}

/*

8 2
1 1
0 1
1 0
1 1
1 1
0 0
1 0
1 1
0 + 2 + 1 + 2 = 5

0 1 0 0
1 1 0 0
0 1 0 0



1 0 0
0 1 1
1 0 0

1 + 1 + 1 = 3 

1 0 0 0
1 1 1 1
0 0 0 0

1 + 2 + 2 = 5

1 0 0 1
0 1 1 1 
0 1 1 0 
1 0 0 1 

0 + 0 + 3 + 0 = 3

1 0 0 1
0 1 1 1 
0 1 1 0 
1 1 0 1 
1 0 1 0

1 + 2 + 1 + 2 = 6

2 7
1 0 1 1 0 1 0
1 0 1 1 0 1 0
1 + 2 + 2 + 1


5 4
1 1 0 1 1
1 1 0 1 1
1 1 0 1 1
1 1 0 1 1
1 1 0 1 1
*/