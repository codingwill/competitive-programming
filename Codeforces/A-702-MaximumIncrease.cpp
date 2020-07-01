#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

ll dp[100005];


void DP(int arr[], int n)
{
    ll highest;
    bool linked = false;
    dp[0] = 1;
    if (n > 1)
    {
        if (arr[0] < arr[1]) linked = true;
    }
    highest = dp[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[i-1]) 
        {
            linked = false;
            dp[i] = 1;
        }
        else
        {
            linked = true;
            dp[i] = dp[i-1] + 1;
        }
        highest = max(highest, dp[i]);
    }
    cout << highest << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    DP(arr, n);
    return 0;
}