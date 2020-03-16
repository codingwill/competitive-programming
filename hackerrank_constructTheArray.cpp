#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using ll = long long int;

ll dp[100005][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = (dp[i-1][2] * (k-1)) % 1000000007;
        dp[i][2] = (dp[i-1][1] + (dp[i-1][2] * (k-2))) % 1000000007;
    }
    
    x == 1 ? cout << dp[n][1] << '\n' : cout << dp[n][2] << '\n';
    return 0;
}
