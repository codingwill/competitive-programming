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

bool vis[105][105];

/*
void DFS(int n, int m, int x, int y)
{
    pair<int, int> node = make_pair(x, y);
    stack<pair<int, int>> nodeList;
    nodeList.push(node);
    
    vis[node.first][node.second] = true;
    while(!nodeList.empty())
    {
        pair<int, int> temp;
        temp = nodeList.top();
        cout << temp.first << ' ' << temp.second << '\n';
        nodeList.pop();
        if (temp.first > 1)
        {
            if (!vis[temp.first - 1][temp.second])
            {
                nodeList.push(make_pair(temp.first-1, temp.second));
                vis[temp.first-1][temp.second] = true;
            }
        }
        if (temp.second > 1)
        {
            if (!vis[temp.first][temp.second - 1])
            {
                nodeList.push(make_pair(temp.first, temp.second-1));
                vis[temp.first][temp.second-1] = true;
            }
        }
        if (temp.first < n)
        {
            if (!vis[temp.first + 1][temp.second])
            {
                nodeList.push(make_pair(temp.first+1, temp.second));
                vis[temp.first+1][temp.second] = true;
            }
        }
        if (temp.second < m)
        {
            if (!vis[temp.first][temp.second + 1])
            {
                nodeList.push(make_pair(temp.first, temp.second+1));
                vis[temp.first][temp.second+1] = true;
            }
        }
    }
}
*/

void solve()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = y; i >= 1; --i)
    {
        cout << x << ' ' << i << '\n';
    }
    for (int i = y+1; i <= m; ++i)
    {
        cout << x << ' ' << i << '\n';
    }
    bool balik = false;
    for (int i = x-1; i >= 1; --i)
    {
        if (balik)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << i << ' ' << j << '\n';
            }
        }
        else
        {
            for (int j = m; j >= 1; --j)
            {
                cout << i << ' ' << j << '\n';
            }
        }
        balik = !balik;
    }
    for (int i = x+1; i <= n; ++i)
    {
        if (balik)
        {
            for (int j = 1; j <= m; ++j)
            {
                cout << i << ' ' << j << '\n';
            }
        }
        else
        {
            for (int j = m; j >= 1; --j)
            {
                cout << i << ' ' << j << '\n';
            }
        }
        balik = !balik;
    }
}
