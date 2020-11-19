#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

//vector<int> memo(200500, 0);
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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

bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}



int low[100500];
int pre[100500];
int step = 0;
set<pair<int, int>> bridge;
int number[100500];

bool vis[100500];
stack<int> q;


void newBridge(int parent, int child)
{
    bridge.insert(make_pair(min(parent, child), max(parent, child)));
}

vector<vector<int>> adj(200050);
void dfs(int start, int dest)
{
    
    pre[dest] = step++;
    low[dest] = pre[dest];
    int count = 0;
    for (auto &i : adj[dest])
    {
        if (pre[i] == 0)
        {
            dfs(adj, dest, i);
            low[dest] = min(low[dest], low[i]);
            if (low[i] > pre[dest])
            {
                newBridge(i, dest);
                //number[dest] = count;
                //count++;
            }
            else
            {
                //number[dest] = number[i];
            }
            
        }
        else if (i != start)
        {
            low[dest] = min(low[dest], pre[i]);
        }
    }
}

void countingGraph(vector<vector<int>>& adj, int start, int dest)
{
    
    q.push(start);
    vis[start] = true;
    ll count = 0;
    while (!q.empty())
    {
        int parent = q.top();
        q.pop();
        
        //cout << parent << '\n';
        for (auto &i : adj[parent])
        {
            if (!vis[i])
            {
                pair<int, int> temp = make_pair(min(parent, i), max(parent, i));
                if (bridge.find(temp) != bridge.end())
                {
                    count++;
                    number[i] = count;
                }
                else
                {
                    number[i] = number[parent];
                }
                
                vis[i] = true;
                q.push(i);
            }
            
        }
    }

}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 5);
    for (int i = 0; i < m; ++i)
    {
        int s, t;
        scanf("%d %d", &s, &t);
        adj[s].push_back(t);
        adj[t].push_back(s);
    }
    dfs(adj, -1, 1);
    countingGraph(adj, 1, n);
    /*
    for (int i = 1; i <= n; ++i)
    {
        cout << number[i] << ' ';
    }
    cout << '\n';
    */
    //cout << adj[2][1] << '\n';
    for (int i = 0; i < q; ++i)
    {
        int s,  t;
        scanf("%d %d", &s, &t);
        //cout << number[s] << ' ' << number[t] << '\n';
        if (number[s] == number[t]) printf("YES\n");
        else printf("NO\n");
        //traverse(adj, s, t) && traverse(adj, t, s)? cout << "YES\n" : cout << "NO\n";
    }
    /*
    for (auto &i : bridge)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
    cout << '\n';
    */
}
 
/*
 
15   
19   
5    
15 14
14 13
12 13
1 12 
1 13 
1 3  
1 2  
2 3  
2 4
4 5
5 6
6 7
7 3
6 8
9 8
9 10
8 10
11 10
8 11
*/