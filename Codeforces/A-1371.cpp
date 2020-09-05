#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/07/01
*/

using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cout << (n+1) / 2 << '\n';
    }
}

/*
5
1
2
3
4
5 

1 2 3 4 5
5 5 5
3

1 2 3 4 5 6
6 6 3 6

1 2 3 4 5 6 7
7 7 7 7
*/