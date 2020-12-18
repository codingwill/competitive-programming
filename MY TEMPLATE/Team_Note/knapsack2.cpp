int n = 10, maxWeight = 50;
int maxSum = 100500;

ll knapsack2()
{
    ll ans = -1;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (ll j = maxSum-1; j >= v[i]; --j)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            if (dp[j] <= maxWeight) 
                ans = max(ans, j);
        }
    }
    return ans;
}