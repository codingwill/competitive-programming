vector<vector<ll>> dp(3, vector<ll>(200050, 0));
 
void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(3, vector<ll>(n+5, 0));
    for (int i = 0; i < n; ++i)
    {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    }
 
    //Dynamic Programming
    dp[0][0] = a[0][0];//base case
    dp[1][0] = a[1][0];
    dp[2][0] = a[2][0];
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j) //3 cara untuk melakukan aktivitas dalam hari pertama
        {
            for (int k = 0; k < 3; ++k) //2 cara untuk melakukan aktivitas di hari kedua 
            {
                if (j == k) continue;
                dp[j][i] = max(dp[j][i], dp[k][i-1] + a[j][i]);
            }
        }
    }
    cout << max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1])) << '\n';
}