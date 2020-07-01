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
    int t;
    cin >> t;
    
    while (t--)
    {
        map<char, int> count;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); ++i)
        {
            ++count[s[i]];
        }
        int pairs = min(count['0'], count['1']);
        pairs % 2 == 0 ? cout << "NET\n" : cout << "DA\n";
        count.clear();
    }
}