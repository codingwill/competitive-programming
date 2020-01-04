#include <bits/stdc++.h>
#include <chrono>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono;

using ll = long long int;

ll sum;
vector<ll> coins; 
ll dp[2000000];
bool isDP[200000];
ll listCoin[2000000];

ll DPTopDown(ll sum)
{
    if (sum < 0) return INT32_MAX;
    if (sum == 0) return 0;
    if (isDP[sum]) return dp[sum];
    ll minim = INT32_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        minim = min(minim, DPTopDown(sum-coins[i])+1);
    }
    dp[sum] = minim;
    isDP[sum] = true;
    return minim;
}

void DPBottomUp(ll sum)
{
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        dp[i] = INT32_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i-coins[j] >= 0 && dp[i] > dp[i-coins[j]] + 1)
            {
                dp[i] = dp[i-coins[j]] + 1;
                listCoin[i] = coins[j];
            }
        }
    }
    cout << dp[sum] << '\n';
    
    for (int i = sum; i > 0; i -= listCoin[i])
    {
        cout << listCoin[i] << ' ';
    }
    
}

/*
Minim combination coin to get sum X;
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll nCoin;
    cin >> sum >> nCoin;
    for (int i = 0; i < nCoin; i++)
    {
        ll input;
        cin >> input;
        coins.push_back(input);
    }
    auto start = high_resolution_clock::now();
    DPBottomUp(sum);
    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>(stop - start);
    cout << "Waktu eksekusi: " << dur.count() << " ms.\n";
    //cout << DPTopDown(sum) << '\n';
    
    return 0;
}