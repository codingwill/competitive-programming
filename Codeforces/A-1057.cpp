#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std
//AUTHOR'S NAME
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1];
    a[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i];
    }
    int node = n;
    vector<int> ans;
    while (true)
    {
        ans.push_back(node);
        node = a[node];
        if (node == 0) break;
    }
    reverse(ans.begin(), ans.end());
    for (int n : ans) cout << n << ' ';
}