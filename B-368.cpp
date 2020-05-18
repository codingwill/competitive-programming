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
    vector<int> a(n), dp(n+5, 0);
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[n] = 1;
    s.insert(a[n-1]);
    m[a[n-1]]++;
    for (int i = n-2; i >= 0; i--)
    {
        if (!s.count(a[i])) 
        {
            dp[i+1] = dp[i+2] + 1;
        }
        else
        {
            dp[i+1] = dp[i+2];
        }
        s.insert(a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;
        cout << dp[input] << '\n';
    }
}