#include <bits/stdc++.h>
#define ll long long
/*
CODE by wkwkwill
*/
using namespace std;

ll int fact(int a)
{
    if (a == 0)
        return 1;
    return a * fact(a-1);
}

bool kombin[3022][3022];
ll int nilaiKombin[3022][3022];

ll int unfairness(ll int arr[], int n, int k)
{
    if (nilaiKombin[])
    ll int index[n];
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }
    ll int total = 0;
    ll int minim;
    total = unfairness(arr, n-1, k) + k
    return minim;
}


int main()
{
    int n, k;
    cin >> n >> k;
    ll int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << unfairness(num, n, k) << endl;
}