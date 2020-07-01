#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/28
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
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(0);
        bool divisible = true;
        for (ll i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            if (input % k != 0) divisible = false;
            a.push_back(input);
        }
        if (divisible)
        {
            cout << 0 << '\n';
            a.clear();
            continue;
        }
        //cari modus
        unordered_map<ll, ll> countMode;
        ll maks = -1;
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] % k != 0) ++countMode[a[i] % k];
            maks = max(maks, countMode[a[i] % k] * k - (a[i] % k) + 1);
        }
        cout << maks << '\n';
    
        a.clear();
    }
}

/*
1
4 2
5 6 2 2
6 8 2 4
1 2 0 2

1
6 9
5 9 12 11 5 4
4 0 
15

10 6
8 7 1 8 3 7 5 10 8 9
8 5 11 4

1 1 2 3


*/