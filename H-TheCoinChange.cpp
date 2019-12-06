#include <bits/stdc++.h>
#define ll long long
/*
CODE by wkwkwill
*/

using namespace std;

bool kombin[300][70];
ll int kombinValue[300][70];


long long int kombinKoin(int arr[], int value ,int nCoin)
{
    
    if (value == 0) return 1;
    else if (value < 0) return 0;
    else if (value > 0 && nCoin <= 0) return 0;
    if (kombin[value][nCoin])
    {
        return kombinValue[value][nCoin];
    }
    long long int total = kombinKoin(arr, value, nCoin - 1) + kombinKoin(arr, value - arr[nCoin - 1], nCoin);
    kombin[value][nCoin] = true;
    kombinValue[value][nCoin] = total;
    return total;
    
}

int main()
{
    memset(kombin, 0, sizeof(kombin));
    int n, m;
    cin >> n >> m;
    int koin[m];
    for (int i = 0; i < m; i++)
    {
        cin >> koin[i];
    }
    cout << kombinKoin(koin, n, m) << endl;
}