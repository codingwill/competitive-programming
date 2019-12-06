#include <bits/stdc++.h>
#define ll long long
/*
CODE by wkwkwill
*/
using namespace std;

ll int kombinCoklat(ll int arr[], ll int minim, int n)
{
    ll int totalKombin = 0;
    ll int totalKombin2 = 0;
    ll int beda;
    ll int hasil;
    for (int i = 0; i < 5; i++)
    {
        totalKombin = 0;
        for (int j = 0; j < n; j++)
        {
            beda = arr[j] - (minim - i);
            totalKombin += (beda / 5) + (beda % 5 / 2) + (beda % 5 % 2);
            //cout << totalKombin << endl;
        }
        if (i == 0)
            hasil = totalKombin;
        else
        {
            hasil = min(totalKombin, hasil);
        }
    }
    return hasil;
}

int main()
{
    int tambahan[3] = {1, 2, 5};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll int coklat[n];
        ll int minim;
        for (int i = 0; i < n; i++)
        {
            cin >> coklat[i];
            if (i == 0)
                minim = coklat[i];
            else
                minim = min(minim, coklat[i]);
        }
        cout << kombinCoklat(coklat, minim, n) << endl;
    }
}
