#include <bits/stdc++.h>
/*
by: wkwkwill
2020/10/03
*/
using namespace std;
using ll = long long int;



void solve()
{
    int t;
    cin  >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n+5);
        vector<int> ibu(n+5);
        vector<bool> vis(n+5, false);
        int minim = INT32_MAX;
        for (int i = 0; i < n-1; ++i)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(make_pair(i+2, b));
            if (a == 1)
            {
                minim = min(minim, b);
            }
            ibu[i+2] = a;
            
        }
        queue<int> q;
        q.push(1);
        int count = 0;
        bool isMinim = false;
        vector<int> ans;
        while (!q.empty())
        {
            minim = INT32_MAX;
            int node = q.front();
            q.pop();
            if (vis[node]) continue;
            vector<pair<int, int>> temp = adj[node];
            for (int i = 0; i < (int)temp.size(); ++i)
            {
                minim = min(minim, temp[i].second);
            }
            for (int i = 0; i < (int)temp.size(); ++i)
            {
                int anak = ibu[temp[i].first];
                q.push(temp[i].first);
                if (node == 1)
                {
                    if (temp[i].second == minim)
                    { 
                        isMinim = true;
                    }
                    else
                    {
                        temp[i].second = minim + (temp[i].second - minim) * 2;   
                    }
                }
                else
                {
                    if (temp[i].second == minim)
                    { 
                        isMinim = true;
                        temp[i].second = temp[i].second + adj[ibu[anak]][anak].second;
                    }
                    else
                    {
                        temp[i].second = minim + ((temp[i].second - minim) * 2) + adj[ibu[anak]][anak].second;
                    }
                }
            }
            if (temp.size() == 0)
            {
                ans.push_back(adj[ibu[node]][0].second);
                isMinim = false;
                count = 0;
            }
            vis[node] = true;
        }
        //sort(ans.begin(), ans.end());
        vector<int> query(100500, 0);
        int index = 0;
        cout << minim << '\n';
        for (auto n : ans)
        {
            cout << n << ' ';
        }
        cout << '\n';
        for (int i = 0; i <= query.size(); ++i)
        {
            if (i == ans[index])
            {
                index++;
                query[i] = index;
            }
            else
            {
                query[i] = index;
            }
        }
        int Q;
        cin >> Q;
        for (int i = 0; i < Q; ++i)
        {
            int input;
            cin >> input;
            cout << query[input] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}