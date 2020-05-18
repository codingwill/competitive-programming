#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (i == 0) dp[i] = input;
        else dp[i] = dp[i-1] + input;
        //cout << "t" << endl;
    }
    ll minim = INT64_MAX;
    int ans = 1;
    for (int i = 0; i < n-k+1; i++)
    {
        if (i == 0) minim = min(minim, dp[i+k-1]);
        else 
        {
            if (minim > dp[i+k-1] - dp[i-1]) ans = i+1;
            minim = min(minim, dp[i+k-1] - dp[i-1]);
        }
        //cout << "t" << endl;
    }
    cout << ans << '\n';
}