#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int faktor[n];
    memset(faktor, 0, sizeof(faktor));
    int totalFaktor = 0;
    int faktorMax = 0;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            n /= i;
            faktor[i]++;
            totalFaktor++;
        }
        if (n == 1)
        {
            faktorMax = i;
            break;
        }
    }
    if (totalFaktor < k)
    {
        cout << "-1" << endl;
        return 0;
    }
    else if (totalFaktor >= k)
    {
        int faktorGabungan = totalFaktor - k;
        int i = 2, nilaiFakGab = 1;
        while (faktorGabungan + 1 > 0 && totalFaktor != k)
        {
            if (faktor[i] != 0)
            {
                nilaiFakGab *= i;
                faktor[i]--;
                faktorGabungan--;
            }
            else
            {
                i++;
            }
        }
        int iFaktor = 0;
        int hasil[totalFaktor];
        int iHasil = 0;
        if (totalFaktor != k)
        {
            hasil[iHasil] = nilaiFakGab;
            iFaktor++;
            iHasil++;
        }
        
        for (int i = 2; i <= faktorMax; i++)
        {
            while (iFaktor <= (k - 1) && faktor[i] != 0)
            {
                hasil[iHasil] = i;
                faktor[i]--;
                iFaktor++;
                iHasil++;
            }
            
        }
        for (int i = 0; i < k - 1; i++)
        {
            cout << hasil[i] << " ";
        }
        cout << hasil[k - 1] << endl;

        return 0;

    }
}