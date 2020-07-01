#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

ll dp[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a, t;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        t.push_back(input);
        if (input == 1) sum += a[i];
    }
    //DP Initialization
    for (int i = 0; i < k; i++)
    {
        if (t[i] == 0) dp[0] += a[i];
    }
    ll maks = dp[0];
    //TWO POINTERS/SLIDING WINDOW ALGORITHM + DP
    for (int i = 1; i < n-k+1; i++) //sliding window
    {
        dp[i] = dp[i-1];
        if (t[i-1] == 0) dp[i] -= a[i-1]; //pointer 1
        if (t[i+k-1] == 0) dp[i] += a[i+k-1]; //pointer 2
        maks = max(maks, dp[i]);
    }
    cout << sum + maks << '\n';
}