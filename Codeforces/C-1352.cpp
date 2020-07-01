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
        int n, k;
        cin >> n >> k;
        if (k % (n-1) != 0)
        {
            cout << ((k / (n-1)) * n) + (k % (n-1)) << '\n';
        }
        else
        {
            cout << ((k / (n-1)) * n) + (k % (n-1)) - 1 << '\n';
        }
    }
}

/*
3 7
3 6 9 12
1 2 4 5 7 8 10 11

4 12
4 8 12 16 20
1 2 3 5 6 7 9 10 11 13 14 15 17 18 19 

((k / (n-1)) * n) + (k % (n-1))
*/