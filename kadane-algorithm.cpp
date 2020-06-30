#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for (int i = 1; i < n; ++i)
    {
        a[i] = max(a[i], a[i-1] + a[i]);
    }
    cout << a[max_element(a.begin(), a.end()) - a.begin()] << '\n';
}