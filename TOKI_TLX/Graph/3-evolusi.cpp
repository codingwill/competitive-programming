#include <bits/stdc++.h>

/*
by: wkwkwill
date: 2020/07/26
*/
using namespace std;

using ll = long long int;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> nodes;
    for (int i = 0; i < m; ++i)
    {
        string x, y;
        cin >> x >> y;
        nodes[y] = x;
    }
    string a, b;
    cin >> a >> b;
    vector<string> ans;
    string nextNode = a;
    ans.push_back(nextNode);
    bool found = false;
    while (nodes.find(nextNode) != nodes.end())
    {
        nextNode = nodes[nextNode];
        ans.push_back(nextNode);
        if (nextNode == b)
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        ans.clear();
        nextNode = b;
        ans.push_back(nextNode);
        while (nodes.find(nextNode) != nodes.end())
        {
            nextNode = nodes[nextNode];
            ans.push_back(nextNode);
            if (nextNode == a)
            {
                found = true;
                break;
            }
        }
    }

    if (found) 
    {
        reverse(ans.begin(), ans.end());
        for (auto n : ans) cout << n << '\n';
    }
    else cout << "TIDAK MUNGKIN" << '\n';
}

/*
ajjibkclmodnpqerestdvcbwxyaz
*/