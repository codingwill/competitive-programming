#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/05/31
*/
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int odd = 0, even = 0;
        bool can = true;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            if (input % 2 == 0) ++even;
            else ++odd;
        }
        if (odd == 0)
        {
            cout << "No" << '\n';
            continue;
        }
        if (x == n)
        {
            if (odd % 2 == 0) can = false;
        }
        else
        {
            if (x % 2 == 0 && even == 0) can = false;
        }
        if (can) cout << "Yes" << '\n';
        else cout << "No" << 
    }
}

/*
7 5
1 1 1 1 2 2 2


*/