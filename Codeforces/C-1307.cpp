#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/16
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

ll dp[26][26], pre[100005][26];

void solve()
{
    string s;
    cin >> s;
    int len = s.length();
    ll maks = -1;
    //single
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (j == s[i] - 'a')
            {
                if (i == 0) pre[i][s[i] - 'a']++;
                else pre[i][s[i] - 'a'] = pre[i-1][s[i] - 'a'] + 1;
            }
            else if (i > 0) pre[i][j] = pre[i-1][j];
            maks = max(maks, pre[i][j]);
        }
    }
    //cout << pre[4][1] << '\n';
    //duo
    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            dp[j][s[i] - 'a'] += pre[i-1][j];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            maks = max(maks, dp[i][j]);
        }
    }
    cout << maks << '\n';
}