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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, bool>> a;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            a.push_back(make_pair(input, false));
        }
        int index = 0;
        int i = index;
        int diff = 0;
        int ans = 0;
        if (n == 1) 
        {
            cout << "T" << '\n';
            continue;
        }
        else if (n >= 2)
        {
            sort(a.begin(), a.end(), sortPairFirst);
            //ans = a[0].first - 1;
            for (int i = 0; i < n-1; ++i)
            {
                ans += a[i].first;                
            }
            if (ans >= a[n-1].first)
            {
                if ((ans + a[n-1].first) & 1) cout << "T" << '\n';
                else cout << "HL" << '\n';
            }
            else cout << "T" << '\n';
            //cout << ans << '\n';
            //cout << a.size() << '\n';
            //for (auto n : a) cout << n.first << ' ';
            //cout << '\n';
        }
    }
}
/*
5
1 3 1 3 4
1 1 3 3 4
1 1 1 1 4

3
1 1 2
0 1 2 L
0 0 2 HL
0 0 1 L
0 0 0 HL

2
3 1
3 0 L
2 0 HL

(YaNG BESAR DULU)
2
3 1
2 1 L
2 0 HL
1 0 L

3
3 2 1
2 2 1 L
2 1 1 HL
1 1 1 L
1 0 1 HL
0 0 1 L
0 0 0 HL

3
3 2 1
3 2 0 L
2 2 0 HL
2 1 0 L
1 1 0 HL
1 0 0 L
0 0 0 HL

3
3 2 1
3 1 1 L
2 1 1 HL
2 1 0 L
1 1 0 HL
1 0 0 L
0 0 0 HL

4
1 2 3 4
0 2 3 4 L
0 1 3 4 H
0 1 2 4 L
0 0 2 4 H
0 0 1 4 L
0 0 1 3 H
0 0 0 3 L
0 0 0 2 H

1 2 3 4
1 2 3 4 
1 1 3 4 L
0 1 3 4 H
0 0 3 4 L
0 0 3 3 H
0 0 2 3 L
0 0 2 2 H
0 0 1 2 L
0 0 1 1 H
0 0 0 1 L
0 0 0 0 H



3
5 3
4 3

2
1 1
0 1 L
0 0 HL

*/