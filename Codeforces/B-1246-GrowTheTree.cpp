#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ll int n;
    cin >> n;
    ll int stik[n];
    for (int i = 0; i < n; i++)
    {
        cin >> stik[i];
    }
    sort(stik, stik+n, cmp);
    ll int hori = 0;
    ll int verti = 0;
    for(int i = 0; i <= (n-1)/2; i++)
    {
        hori += stik[i];
    }
    for (int i = n-1; i > (n-1)/2; i--)
    {
        verti += stik[i];
    }
    cout << hori*hori + verti*verti << endl;
    return 0;
}