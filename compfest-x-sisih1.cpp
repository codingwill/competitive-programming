#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/05
*/
using namespace std;
using ll = long long int;

bool mySort(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            a.push_back(make_pair(min(a,b), max(a,b)));
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i].first)
        }
    }
}