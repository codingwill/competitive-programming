
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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll one = 0, two = 0;
        for (int i = 0; i < n; ++i)
        {
            string a;
            cin >> a;
            int adj = 0;
            for (int j = 0; j < a.length(); ++j)
            {
                //one
                if (a[j] == '.')
                {
                    ++one;
                    adj += 1;
                }
                if (a[j] == '*') adj = 0;
                if (adj == 2)
                {
                    ++two; 
                    adj = 0;
                    //cout << i << ' ' << j << endl;
                }
            }
        }
        //cout << one << " " << two << endl;
        ll ans = min(one * x, (two * y) + (one - (two*2)) * x);
        cout << ans << '\n';
    }
}

/*
3 3 3 6
..*
*..
.*.

1: 18
2: 16
*/