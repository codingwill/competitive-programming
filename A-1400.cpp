#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/25
*/
using namespace std;
using ll = long long int;

void solve();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int zero = 0, one = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0') zero++;
            else one++;
        }
        if (n == 1)
        {
            cout << s << '\n';
        }
        else
        {
            for (int i = 0; i < s.length(); i += 2)
            {
                cout << s[i];
            }
            cout << '\n';
        }
    }
}

/*
1011001
1001
1100

0000111
0000

1101100
1110

10011010100
100000

11110
100

01010
111

01001

010
10
*/