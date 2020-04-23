#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;
        while (n > 0)
        {
            if (x <= 10) break;
            x = x/2 + 10;
            n--;
        }
        while (m > 0)
        {
            x -= 10;
            m--;
        }
        while (n > 0)
        {
            if (x <= 10) break;
            x = x/2 + 10;
            n--;
        }
        //cout <<  x << endl;
        if (x <= 0)
        {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}

/*
(((h/2 + 10) / 2 + 10) / 2 + 10)
*/