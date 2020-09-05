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

void solve()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> count(2, 0);
        string s;
        getline(cin, s);
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == 'M') count[0]++;
            else if (s[i] == 'F') count[1]++;
        }
        if (count[0] == count[1] && count[0] + count[1] > 2) cout << "LOOP" << '\n';
        else cout << "NO LOOP" << '\n';
    }    
}