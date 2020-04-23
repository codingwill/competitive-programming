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
        int n, k;
        cin >> n >> k;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        int count = 0;
        int l = 1, l_min = 0;
        int maks = -1;
        for (int i = 1; i < n-1; i++)
        {
            if (i >= k-1) l++;
            if (i >= k-1)
            {
                if (a[i - (k-2)] > a[i - (k-1)] && a[i - (k-2)] > a[i - (k-3)])
                {
                    //cout << i << endl;
                    count -= 1;
                } 
            }
            if (a[i] > a[i-1] && a[i] > a[i+1])
            {
                count += 1;
            }
            if (count > maks)
            {
                maks = count;
                l_min = l;
            }
            //cout << l << endl;
        }

        cout << maks + 1 << ' ' << l_min << '\n';
    }
}
/*
5
8 6
1 2 4 1 2 4 1 2
===
3 2
2 7 == segm
2 [4 1 2 4] 1

5 3
3 2 3 2 1
10 4
4 3 4 3 2 3 2 1 0 1
15 7
3 7 4 8 2 3 4 5 21 2 3 4 2 1 3
7 5
1 2 3 4 5 6 1
*/