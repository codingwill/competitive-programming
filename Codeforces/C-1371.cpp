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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (n+m > a+b)
        {
            cout << "No" << '\n';
        }
        else if (m == 0)
        {
            cout << "Yes" << '\n';
        }
        else if (a <= b)
        {
            if (m <= a) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
        else
        {
            if (m <= b) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        } 
        
        
        
    }
}

/*
3 2 2 3
3 1 2 2 
2 1 1 2
2 0 1 1
1 0 0 1


5 4 6 2
4 4 5 2


2 2 1 1
2 1 0 1
2 0 0 0

2 2 1 1
1 2 1 0
1 1 1 0

2 2 2 2
0 2 2 0
0 0 0 0 

1
3 4 2 4
3 2 0 4
3 0 0 2
angry

3 4 2 4
0 4 2 1
0 2 0 1
angry

3 4 2 4
3 3 1 4
2 3 1 3
2 2 0 3
0 2 0 1
angry

3 4 3 4
3 
*/