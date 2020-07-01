#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

ll dp[6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> key;
    key[4] = 0;
    key[8] = 1;
    key[15] = 2;
    key[16] = 3;
    key[23] = 4;
    key[42] = 5;
    bool possible = true;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n-1; i >= 0; --i)
    {
        dp[key[a[i]]]++;
        if (key[a[i]] != 5)
        {
            if (dp[key[a[i]]] > dp[key[a[i]]+1])
            {
                count++;
            }
        }
    }
    if (n < 6)
    {
        cout << n << '\n';
        return 0;
    }
    cout << count << '\n';
    

}
/*
1
4 [4] [4] 8 [8] 15 [8] 16 [16] [15] 23 42 [23] [42]
4 4 4 8 8 15 8 16 16 15 23 42 23 42
*/