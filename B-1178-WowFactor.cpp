#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

using ll = long long int;
ll dp[1000005];
ll w[1000005];
ll o[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    dp[0] = 0;

    for (int i = 1; i < s.length(); i++)
    {
        w[i] = w[i-1];
        o[i] = o[i-1];
        dp[i] = dp[i-1];
        if (s[i] == 'v')
        {
            if (s[i-1] == 'v')
            {
                if (o[i] > 0)
                {
                    dp[i] += o[i];
                }
                w[i]++;
            }
        }
        else
        {
            o[i] += w[i];
        }
    }
    cout << dp[s.length()-1] << '\n';
    return 0;
}