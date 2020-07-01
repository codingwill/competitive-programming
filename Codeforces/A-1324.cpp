#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;



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
        vector<int> a;
        int maks = -1;
        int minim = INT32_MAX;
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
            maks = max(input, maks);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (abs(a[i] - maks) % 2 == 1) 
            {
                can = false;
                break;
            }
        }
        if (can) puts("YES");
        else puts("NO");
    }
    return 0;
}