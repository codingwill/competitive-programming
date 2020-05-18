#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int dp[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0)
            {
                if (s[i] == '1') dp[i] = 1;
                else dp[i] = 0;
                continue;
            }
            if (s[i] == '1')
            {
                
                dp[i] = dp[i-1] + 1;
            }
            else dp[i] = dp[i-1];
        }
        int l = 0, r = 0;
        ll count = 0, count2 = 0;
        while (l <= n-1)
        {
            if (s[l] == '1')
            {
                r = l+1;
                int dist = 0;
                while (r < l+k)
                {
                    if (r > n-1) break;
                    if (s[r] == '1')
                    {
                        count += 1;
                        //cout << 't' << endl;
                        //cout << l << " " << r << endl;
                    }
                    r++;
                }
                if (r > n-1) break;
                if (s[r] == '0' && dp[n-1]-dp[r] > 0)
                {
                    count += 1;
                    //cout << 't' << endl;
                }
                l = r;
            }
            else
            {
                l++;
            }
        }
        //right
        while (r >= 0)
        {
            if (s[r] == '1')
            {
                l = r-1;
                int dist = 0;
                while (l > r-k)
                {
                    if (l < 0) break;
                    if (s[l] == '1')
                    {
                        count2 += 1;
                    }
                    l--;
                }
                if (l < 0) break;
                if (s[l] == '0' && dp[l] > 0)
                {
                    count2 += 1;
                    //cout << 't' << endl;
                }
                r = l;
            }
            else
            {
                r--;
            }
        }
        //int l = n-1, r = n-1;
        //for (int i = n-1; i >= 0; i--)
        //{
            
        //}
        cout << min(count2, count) << '\n';
    }
}