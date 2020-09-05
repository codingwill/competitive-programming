#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
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

bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairFirst(pair<int, bool> &a, pair<int, bool> &b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}


void solve()
{
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> count(26, 0);
    for (int i = 0; i < s.length(); ++i)
    {
        int index = s[i] - 'A';
        count[index]++;
    }
    for (int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        string strUpdate;
        cin >> strUpdate;
        int index = c - 'A';
        ll temp = count[index];
        count[index] = 0;
        for (int i = 0; i < strUpdate.length(); ++i)
        {
            index = strUpdate[i] - 'A';
            count[index] += temp;
        }
    }
    ll ans = 0;
    for (ll n : count) ans += n;
    cout << ans << '\n';
    //cout << count['M' - 'A'] << '\n';
}
/*

*/