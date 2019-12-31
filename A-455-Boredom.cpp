#include <bits/stdc++.h>
#include <chrono>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono;

using ll = long long int;

ll dp[200005];
ll counter[200005];

int main()
{
    int n;
    scanf("%d", &n);
    int t = n;
    int maxInput = INT32_MIN;
    while (t--)
    {
        int input;
        scanf("%d", &input);
        counter[input]++;
        maxInput = max(maxInput, input);
    }
    dp[0] = 0;
    dp[1] = counter[1];
    for (ll i = 2; i <= maxInput; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + counter[i]*i);
    }
    cout << dp[maxInput] << '\n';
    return 0;
}   