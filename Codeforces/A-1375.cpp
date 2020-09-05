#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/04
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    
    int neg = 0;
    int pos = 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i += 2)
        {
            if (pos >= n/2)
            {
                
                continue;
            }
            if (neg >= n/2)
            {

                continue;
            }
            if (a[i+1] - a[i] == 0)
            {
                pos++;
                neg++;
            }
            else if (a[i+1] - a[i] < 0)
            {
                neg++;
            }
            else
            {
                pos++;
            }
        }
        for (int n : a)
        {
            cout << n << ' ';
        }
    }
}