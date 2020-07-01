    #include <bits/stdc++.h>
    
    //BIAR MANTAB LAH YA
    #define Willy using
    #define Indrayana namespace
    #define Komara std
    
    Willy Indrayana Komara;
    
    using ll = long long int;
    
    int dp[4][200005];
    
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
        while (t--)
        {
            string s;
            cin >> s;
            set<int> him;
            for (int i = s.length()-1; i >= 0; i--)
            {
                him.insert(s[i]-'0');
                if (i == s.length()-1)
                {
                    dp[s[i]-'0'][i] = i;
                    dp[myMod((s[i]-'0') + 1, 3)][i] = INT32_MAX;
                    dp[myMod((s[i]-'0') + 2, 3)][i] = INT32_MAX;
                }
                else
                {
                    dp[s[i]-'0'][i] = i;
                    dp[myMod((s[i]-'0') + 1, 3)][i] = dp[myMod((s[i]-'0') + 1, 3)][i+1];
                    dp[myMod((s[i]-'0') + 2, 3)][i] = dp[myMod((s[i]-'0') + 2, 3)][i+1];
                }
            }
            if (him.size() != 3)
            {
                cout << 0 << '\n';
                him.clear();
                continue;
            }
            him.clear();
            int ans = INT32_MAX;
            for (int i = 0; i < s.length()-2; i++)
            {
                ans = min(ans, max(dp[myMod((s[i]-'0') + 1, 3)][i] - i + 1,  dp[myMod((s[i]-'0') + 2, 3)][i] - i + 1));
            }
            cout << ans << '\n';
        }
    }
    
    /*
    111111122222222222222333333313332123333333
    7 14 7


    12222133333332
    213
    3
    
    112233
    1223
    4
    
    12121212
    
    0
    
    31121
    3112
    4
    
    31121
    */