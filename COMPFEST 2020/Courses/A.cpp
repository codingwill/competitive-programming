#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
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
    int n, m;
    cin >> n >> m;
    set<int> digit;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        digit.insert(input);
    }
    int kelipatan = m;
    for (int i = m; i <= 1000000; i += kelipatan)
    {
        set<int> kombin;
        string s = to_string(i);
        for (int j = 0; j < s.length(); ++j)
        {
            int temp = s[j] - '0';
            kombin.insert(temp);
        }
        if (kombin == digit)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;

}
/*

*/