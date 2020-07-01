#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        n -= input;
    }
    if (n < 0) n = -1;
    cout << n << '\n';
}