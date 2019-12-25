#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int kiri = n-1, kanan = n;
        int jar[n*2];
        int nDua = 0, nSatu = 0;
        for (int i = 0; i < 2*n; i++)
        {
            cin >> jar[i];
            if (jar[i] == 1) nSatu++;
            else nDua++;
        }
        for (int i = 0; i < 2*n; i++)
        {
            if (jar[kiri] == max(nSatu, nDua) || jar[kanan])
        }
    }
}