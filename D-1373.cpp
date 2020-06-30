#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/30
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
        int n;
        cin >> n;
        vector<ll> a;
        ll sumReverse = 0;
        ll sumTot = 0;
        ll maksSumReverse = 0;
        for (int i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            a.push_back(input);
            if (i % 2 == 0) sumTot += input;
        }

        //starts from even
        for (int i = 1; i < n; i += 2)
        {
            sumReverse += a[i] - a[i-1];
            if (sumReverse < 0) sumReverse = 0;
            maksSumReverse = max(maksSumReverse, sumReverse);
        }
        maksSumReverse = max(maksSumReverse, sumReverse);
        sumReverse = 0;
        //starts from odd
        for (int i = 2; i < n; i += 2)
        {
            sumReverse += a[i-1] - a[i];
            if (sumReverse < 0) sumReverse = 0;
            maksSumReverse = max(maksSumReverse, sumReverse);
        }
        maksSumReverse = max(maksSumReverse, sumReverse);
        //cout << sumTot << ' ' << maksSumReverse << '\n';
        cout << sumTot + maksSumReverse << '\n';
    }
}
/*
7 8 4 5 7 6 8 9 7 3
7 4 7 8 7 = 33
7 8 7 8 7 = 37

*/