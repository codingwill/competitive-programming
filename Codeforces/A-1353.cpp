#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n > 2)
        {
            cout << m * 2 << '\n';
        }
        else if (n == 2) cout << m << '\n';
        else cout << 0 << '\n';
    }
}

/*
4 5
0 2 0 3 = 2 + 2 + 3 = 7
0 5 0 0 = 5 + 5 = 10

5 5
0 5 0 0 0 = 5 + 5 + 0 + 0 = 10

4 10
0 4

1 100 = 0
2 2 = 2

*/