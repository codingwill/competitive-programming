#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define lli long long int

using namespace std;

int emberBact[1000005]; 

bool besarDulu(int a, int b)
{
    return a > b;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int bact[n];
    rep(i, n)
    {
        cin >> bact[i];
        emberBact[bact[i]]++;
    }
    sort(bact, bact+n);
    int berkurang = 0;
    //int pemakan = 1, termakan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (bact[i] < bact[i+1] && bact[i] + k>= bact[i+1])
        {
            berkurang += emberBact[bact[i]];
        }
    }
    cout << n - berkurang << "\n";
}
