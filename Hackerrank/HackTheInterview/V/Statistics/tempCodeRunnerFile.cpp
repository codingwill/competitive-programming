#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/05
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a;
    double mean = 0, median;
    ll mode;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        mean += input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    mean /= n;
    median = (n & 1 ? a[n/2] : double(a[n/2] + a[n/2 - 1])/2);
    ll count = 0;
    ll maks = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            count++;
            mode = a[i];
        }
        else
        {
            if (a[i] == a[i-1]) count++;
            else
            {
                count = 0;
            }
            
            if (count > maks)
            {
                mode = a[i];
            }
        }
    }
    cout << fixed << setprecision(3) << mean << '\n' << median << '\n' << mode << '\n';
}