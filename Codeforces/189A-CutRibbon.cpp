#include <bits/stdc++.h>

using namespace std;

int dp[4005];
int possible[300000];
int kombin[4005][4005];
int i = 0;

long long int kombinKoin(int arr[], int value, int iRibbon, int nRibbon)
{
    if (value == 0) 
    {
        possible[i] = nRibbon;
        i++;
        return 0;
    }
    else if (value < 0) 
        return 0;
    else if (value > 0 && iRibbon <= 0) 
        return 0;
    if (kombin[value][iRibbon])
    {
        return kombinValue[value][iRibbon];
    }
    long long int total = kombinKoin(arr, value, iRibbon - 1, nRibbon+1) + 
                          kombinKoin(arr, value - arr[iRibbon - 1], iRibbon, nRibbon+1);
    kombin[value][iRibbon] = true;
    kombinValue[value][iRibbon] = total;
    return total;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
}