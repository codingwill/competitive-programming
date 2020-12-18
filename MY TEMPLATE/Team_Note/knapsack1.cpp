vector<vector<ll>> dp(105, vector<ll>(100500, 0));
 
void knapsack1()
{
    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<int> v(n+1), w(n+1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= maxWeight; ++j)
        {
            if (j >= w[i])
            {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-w[i]]);
            }
            else
            {
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    cout << dp[n][maxWeight] << '\n';
}