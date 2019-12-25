#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maks = INT_MIN;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        maks = max(maks, x+y);
    }
    cout << maks << "\n";
    return 0;
}

Problem tag/category: Math
Level (codeforces): 1100