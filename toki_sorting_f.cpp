#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/05
*/
using namespace std;
using ll = long long int;

bool mySort(const string &a, const string &b)
{
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;
        a.push_back(input);
        sort(a.begin(), a.end());
        auto it = find(a.begin(), a.end(), input);
        ans.push_back(it - a.begin());
    }
    for (int n : ans) cout << n+1 << '\n';
}