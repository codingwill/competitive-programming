#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int num = t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> dp[i];
            if (i > 0) dp[i] += dp[i-1];
        }
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i > 0)
                {
                    double akar = sqrt(dp[j] - dp[i-1]);
                    if (akar - int(akar) <= 1e-6)
                    {
                        ans++;
                    }
                }
                else
                {
                    double akar = sqrt(dp[j]);
                    if (akar - int(akar) <= 1e-6)
                    {
                        ans++;
                    }
                }
                
            }
        }
        cout << "Case #" << num-t << ": " << ans << endl;
        
    }
}