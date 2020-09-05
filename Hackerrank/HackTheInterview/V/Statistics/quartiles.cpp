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
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    //for (int n : a) cout << n << ' ';
    //cout << '\n';
    if (n & 1)
    {
        if (n/2 & 1) cout << a[n/2/2] << '\n';
        else 
        {
            cout << double(a[n/2/2] + a[n/2/2 - 1]) / 2 << '\n';
        }
        cout << a[n/2] << '\n';
        if (n/2 & 1) cout << a[n/2/2 + n/2] << '\n';
        else 
        {
            cout << double(a[n - n/2/2] + a[n - n/2/2 - 1]) / 2 << '\n';
        }
    }
    else
    {
        if (n/2 & 1) cout << a[n/2/2] << '\n';
        else 
        {
            cout << double(a[n/2/2] + a[n/2/2 - 1]) / 2 << '\n';
        }
        cout << double(a[n/2] + a[n/2 - 1]) / 2 << '\n';
        if (n/2 & 1) cout << a[n/2/2 + n/2] << '\n';
        else 
        {
            cout << double(a[n - n/2/2] + a[n - n/2/2 - 1]) / 2 << '\n';
        }
    }
    
}