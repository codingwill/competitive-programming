#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/01
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    cin.ignore();
    map<ll, ll> a;
    map<ll, ll> ans;
    for (int i = 0; i < n; ++i)
    {
        ll input;
        cin >> input;
        a[input] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        ll input;
        cin >> input;
        ++ans[a[input] - i];
        if (a[input] - i < 0)
        {
            ++ans[n - abs(a[input] - i)];
        }
        else if (a[input] - i > 0)
        {
            ++ans[- (n - (a[input] - i))];
        }
    }

    ll maks = -1;
    for (pair<ll, ll> n : ans)
    {
        maks = max(maks, n.second);
    }
    cout << maks << '\n';
}