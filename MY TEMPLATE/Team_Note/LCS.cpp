vector<vector<int>> dp(3005, vector<int>(3005, 0));
string s, t, ans = "";
int maxLen = -1;
 
void LCS()
{
    for (int i = 1; i <= s.length(); ++i)
    {
        for (int j = 1; j <= t.length(); ++j)
        {
            if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    //cout << 't' << '\n';
    int count = 1;
    int i = s.length(), j = t.length();
    while (i >= 1 && j >= 1)
    {
        if (dp[i][j] != dp[i-1][j] && dp[i][j] != dp[i][j-1])
        {
            ans = s[i-1] + ans;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j] == dp[i-1][j])
            {
                i--;
            }
            else if (dp[i][j] == dp[i][j-1])
            {
                j--;
            }
        }
    }
}