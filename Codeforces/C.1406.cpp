#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 998244353;

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

bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> adj(100005);
        vector<set<int>> sudah(100005);
        vector<int> sameEdge(100005, 0);
        set<int> nodeSet;
        int n;
        cin >> n;

        vector<int> nodeMax;
        for (int i = 0; i < n-1; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            sudah[x].insert(y);
            sudah[y].insert(x);
        }
        int maks = -1;
        for (int i = 0; i < adj.size(); ++i)
        {
            maks = max(maks, (int)adj[i].size());
        }
        for (int i = 0; i < adj.size(); ++i)
        {
            if (adj[i].size() == maks)
            {
                nodeMax.push_back(i);
                nodeSet.insert(i);
                for (int j = 0; j < adj[i].size(); ++j)
                {
                    sameEdge[adj[i][j]]++;
                }
            }
        }
        if (nodeMax.size() == 1)
        {
            cout << nodeMax[0] << ' ' << adj[nodeMax[0]][0] << '\n';
            cout << nodeMax[0] << ' ' << adj[nodeMax[0]][0] << '\n';
        }
        else
        {
            int node, parent;
            for (int j = 0; j < nodeMax.size(); ++j)
            {
                bool found = false;
                for (int i = 0; i < adj[nodeMax[j]].size(); ++i)
                {
                    if (nodeSet.find(adj[nodeMax[j]][i]) == nodeSet.end())
                    {
                        if (sameEdge[adj[nodeMax[j]][i]] == 1)
                        {
                            node = adj[nodeMax[j]][i];
                            found = true;
                            parent = nodeMax[j];
                            break;
                        }
                    }
                }
                if (found) break;
            }
            
            cout << node  << ' ' << parent << '\n';
            if (parent != nodeMax[0]) cout << node << ' ' << nodeMax[0] << '\n';
            else cout << node << ' ' << nodeMax[1] << '\n';
            //cout << parent << ' ' << nodeMax[0] << '\n';
        }
        adj.clear();
        sudah.clear();

    }
}