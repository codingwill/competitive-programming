#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

ll fact(int a, int b)
{
    ll combi = 1;
    for (int i = a; i > b; i--)
    {
        combi *= i;
        combi = combi % 1000000007;
        //cout << combi << ' ';
        cout << 't' << endl;
    }
    //cout << endl;
    return combi;
}

ll combiCount(int n, int k)
{
    ll combi = 0;
    for (int i = k; k <= n; k++)
    {
        combi += fact(n, max(k, n-k))/fact(min(k, n-k), 0) % 1000000007;
        combi -= (ceil((float)(n-1)/k)-1);
        //cout << combi << " ";
    }
    //cout << endl;
    return combi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout << combiCount(n+1, k) << '\n';
}