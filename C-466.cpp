#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

ll dp[500500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), idx, idx2;
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        if (i == 0) dp[i] = a[i];
        else dp[i] = dp[i-1] + a[i];
    }
    int l = 1, r = 2;
    ll bag[3];
    ll ans = 0;
    ll part1 = dp[n-1] / 3;
    int lb1, ub1, lb2, ub2;
    ll part2 = part1 * 2;
    if (dp[n-1] % 3 != 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (dp[i-1] == part1) idx.push_back(i);
        if (dp[i-1] == part2) idx2.push_back(i);
    }
    for (int i = 0; i < idx.size(); i++)
    {
        ans += idx2.end() - lower_bound(idx2.begin(), idx2.end(), idx[i]+1);
    }
    cout << ans << "\n";
}