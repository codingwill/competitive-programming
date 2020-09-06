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
vector<ll> parent(100050, -1);
vector<bool> visited(100050, false);
set<pair<ll, ll>> s1, s2;
set<pair<ll, ll>> hasil;

void BFS(vector<vector<ll>> &adj)
{
    ll start;
    int graphCount= 0;
    bool tree = true;
    for (int i = 1; i < adj.size(); ++i)
    {
        if (!visited[i])
        {
            graphCount++;
            queue<ll> q;
            q.push(i);
            while (!q.empty())
            {
                ll current = q.front();
                visited[current] = true;
                q.pop();
                for (int i = 0; i < adj[current].size(); ++i)
                {
                    if (!visited[adj[current][i]]) 
                    {
                        q.push(adj[current][i]);
                        parent[adj[current][i]] = current;
                    }
                    else if (parent[current] != adj[current][i])
                    {
                        tree = false;
                    }
                }
            }
        }
    }
    //cout << 't' << '\n';
    if (tree && graphCount == 1) cout << "Pohon\n";
    else cout << "Bukan pohon\n";
    //cout << graphCount << '\n';
    
    
}


void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    
    for (int i = 0; i < k; ++i)
    {
        ll u, v;
        cin >> u >> v;
        s1.insert(make_pair(u, v));
    }
    
    ll l;
    cin >> l;
    for (int i = 0; i < l; ++i)
    {
        ll u, v;
        cin >> u >> v;
        s2.insert(make_pair(u, v));
    }
    for (auto n : s1)
    {
        if (s2.find(make_pair(n.first, n.second)) == s2.end() && 
            s2.find(make_pair(n.second, n.first)) == s2.end() )
        {
            hasil.insert(n);
        }
    }
    for (auto n : s2)
    {
        if (s1.find(make_pair(n.first, n.second)) == s1.end() && 
            s1.find(make_pair(n.second, n.first)) == s1.end() )
        {
            hasil.insert(n);
        }
    }
    vector<vector<ll>> adj(n+1);
    //cout << "ADJ\n===============" << '\n';
    for (auto n : hasil)
    {
        adj[n.first].push_back(n.second);
        if (n.first != n.second) adj[n.second].push_back(n.first);
        //cout << n.first << ' ' << n.second << '\n';
    }
    /*
    for (int i = 0; i < adj.size(); ++i)
    {
        for (int j = 0; j < adj[i].size(); ++j)
        {
            cout << i << ' ' << adj[i][j] << '\n';
        }
    }
    */
    BFS(adj);
    
}
/*
100 25
19

9 2
1 2

3
2
1 3
1 2
2
1 1
2 3
Bukan pohon
*/
