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
    double mean = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        ll input;
        cin >> input;
        a.push_back(input);
        mean += input;
    }
    mean /= n;
    for (int i = 0; i < n; ++i)
    {
        sum += pow((double)a[i] - mean, 2);
    }

    double ans = sqrt(sum/n);
    cout << fixed << setprecision(1) << ans << '\n';
}

/*
RRB 4/7 * 5/9 * 4/8 = 80/504
RBR 4/7 * 4/9 * 4/8 = 64/504
BRR 3/7 * 5/9 * 4/8 = 60/504
============================= +
                      204/504
                       17/42
*/