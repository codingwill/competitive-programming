#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        vector<int> e(n);
        for (int i = 0 ; i < n; i++)
        {
            cin >> e[i];
        }
        sort(e.begin(), e.end());
        int cnt = 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (e[i] == cnt)
            {
                ans++;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
2
3
1 1 1
5
2 3 1 2 2

1 2 2 2 3
|1 |2 2|

(1 + 2 + 3) / 3
3 2 2 | 2 1


5 4 3 2 1

1 2 2 2 3
1 1 2 1 
1 + 1 + 
*/