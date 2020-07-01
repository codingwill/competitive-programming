#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll kem;
    cin >> kem;
    ll t;
    cin >> t;
    ll coin[t];
    for (int i = 0; i < t; i++) cin >> coin[i];
    ll dp[kem + 1];
    dp[0] = 0;
    for(ll i = 1; i < kem; i++) dp[i] = INT64_MAX;
    for (ll i = 1; i <= kem; i++) 
    { 
        for (ll j = 0; j < t; j++)
        {
            if (coin[j] <= i) 
            { 
                ll temp = dp[i - coin[j]]; 
                if (temp != INT64_MAX && temp + 1 < dp[i]) 
                dp[i] = temp + 1; 
            } 
        }   
    } 
    cout << dp[kem];
    return 0; 
} 