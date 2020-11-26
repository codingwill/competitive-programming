#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> dp(200005, 0);
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        dp[i] = abs(a[i] - a[i-1]) + dp[i-1];
        for (int j = 2; j <= k && i-j >= 0; ++j)
        {
            dp[i] = min(abs(a[i] - a[i-j]) + dp[i-j], dp[i]);
        }
    //cout << dp[i] << '\n';
    }
    cout << dp[n-1] << '\n';
}