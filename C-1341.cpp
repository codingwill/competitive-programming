#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool kurungComp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p;
        bool can = false;
        int start = -(n - 1);
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            p.push_back(input);
        }
        for (int i = 0; i < n-1; i++)
        {
            if (abs(start) % 2 == 0) start = abs(start) * -1;
            //cout << start << endl;
            if (p[i] - p[i+1] == start)
            {
                start = abs(start);
                start -= 1;
            }
            else
            {
                can = true;
                //break;
            }
            
        }
        if (can || n <= 1) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
/*
5
5
2 3 4 5 1

1
1

3
1 3 2
==
1: r = [1, 2, 3], count = [1, 1, 1] choose 1. occup[1] = true
2: r = [X, 2, 3], count = [0, 1, 1] choose 3. occup[3] = true
3: r = [X, 2, X], count = [0, 1, 0]. r3 = 3 -> already occupied -> "No"


4
4 2 3 1
==
1: r = [1, 2, 3, 4], count = [1, 1, 1, 1] choose 4. occup[4] = true.
2: r = [1, 2, 3, X], count = [1, 1, 1, 0] choose 2. occup[2] = true.
3: r = [1, 3, 3, X], count = [1, 0, 2, 0] choose 3. occup[3] = true.
4: r = [1, X, X, X], count = [1, 0, 0, 0] choose 1. occup[1] = true. 

5
1 5 2 4 3
==
1: r = [1, 2, 3, 4, 5] count = [1, 1, 1, 1, 1] choose 1.
2: r = [X, 2, 3, 4, 5] count = [0, 1, 1, 1, 1] choose 3.
3: r = [X, 2, 5, 4, 5] count = [0, 1, 0, 1, 2] choose 5.
4: r = [X, 2, 4, 4, X] count = [0, 1, 0, 2, 0] choose 4.
*/