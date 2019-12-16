#include <bits/stdc++.h>

using namespace std;

int dp[100000];

int main()
{
    int a = 3;

    for (int i = 0; i < 10; i++)
    {
        if (dp[3])
        {
            cout << dp[3] << " (nilai ini diambil dari MEMORI)" << endl; 
            continue;
        }
        
        dp[3] = a * a;
        cout << dp[3] << " (nilai ini didapatkan dari HASIL KOMPUTASI)" << endl;
    }
}