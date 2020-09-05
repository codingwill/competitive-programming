#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
*/
using namespace std;
using ll = long long int;

int main()
{
    ll n;
    cin >> n;
    ll maks = -1;
    for (int i = 0; i < n; ++i)
    {
        ll input;
        cin >> input;
        maks = max(maks, input);
    }
    //cout << ((maks - n) & 1) << '\n';
    ((maks - n) & 1) == 0 ? cout << "Bob" : cout << "Alice";
    cout << '\n'; 
}
/*
5
1 2 4 5 7
*/