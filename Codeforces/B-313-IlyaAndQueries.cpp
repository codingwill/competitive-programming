#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool highFirst(const int &a, const int &b)
{
    return a > b;
}

ll dp[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    dp[0] = 0;
    for (int i = 0; i < s.length()-1; i++)
    {
        if (s[i] == s[i+1])
        {
            if (i == 0)
                dp[i+1] = 1;
            else
            {
                dp[i+1] = dp[i] + 1;
            }   
        }
        else
        {
            if (i == 0)
                dp[i+1] = 0;
            else
            {
                dp[i+1] = dp[i];
            }
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        int lower, upper;
        cin >> lower >> upper;
        cout << dp[upper-1] - dp[lower-1] << '\n';
    }
    return 0;

}