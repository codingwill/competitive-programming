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
    int n;
    cin >> n;
    map<int, int> boss;
    for (int i = 1; i < n; i++)
    {
        int input;
        cin >> input;
        boss[input]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << boss[i] << '\n';
    }
}