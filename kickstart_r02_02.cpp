#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    ll z = 1;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<ll> a;
        ll aFinal[n];
        for (int  i = 0; i < n; i++)
        {
            ll input;
            cin >> input;
            a.push_back(input);
        }
        ll maxLate = d;
        ll start = maxLate;
        for (int i = 0; i < n; i++)
        {
            aFinal[i] = a[i] * (d / a[i]);
        }
        for (int i = n-1; i > 0; i--)
        {
            if (aFinal[i] > aFinal[i-1])
            {
                aFinal[i] = aFinal[i] - ((aFinal[i] - a[i-1]) / a[i] * a[i]);
            }
            else if (aFinal[i-1] > aFinal[i])
            {
                aFinal[i-1] = aFinal[i-1] - (ceil((float)(aFinal[i-1] - a[i])/a[i-1]) * a[i-1]);
            }
        }
        cout << "Case #" << z  << ": " << aFinal[0] << '\n';
        z++; 
    }
}