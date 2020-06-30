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
    ll n, k;
    cin >> n >> k;
    vector<ll> bothLike, aliceLikes, bobLikes;
    for (int i = 0; i < n; ++i)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        if (a == b && a == 1 && b == 1)
        {
            bothLike.push_back(t);
        }
        else if (a == 1)
        {
            aliceLikes.push_back(t);
        }
        else if (b == 1)
        {
            bobLikes.push_back(t);
        }
    }
    sort(aliceLikes.begin(), aliceLikes.end());
    sort(bobLikes.begin(), bobLikes.end());
    int i = 0;
    while (i < min(aliceLikes.size(), bobLikes.size()))
    {
        bothLike.push_back(aliceLikes[i] + bobLikes[i]);
        ++i;
    }    
    if (k > bothLike.size())
    {
        cout << -1 << '\n';
        return 0;
    }
    sort(bothLike.begin(), bothLike.end());
    ll ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += bothLike[i];
    }
    cout << ans << '\n';

    
}