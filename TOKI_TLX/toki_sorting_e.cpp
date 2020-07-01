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
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), mySort);
    for (string n : a) cout << n << '\n';
}