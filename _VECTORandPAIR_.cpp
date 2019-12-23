#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> a;
    a.insert(make_pair('a', 6));
    vector<pair<char, int>> s;
    s.push_back(make_pair('a', 6));
    cout << a['a'] << endl;
    cout << s[0].first << ' ' << s[0].second << endl;
}