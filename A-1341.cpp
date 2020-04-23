#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool kurungComp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        if ((a+b) * n < (c-d) || (a-b) * n > (c+d))
        {
            puts("No");
            continue;
        }
        puts("Yes");
    }
}