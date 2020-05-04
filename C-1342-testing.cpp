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
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int count = 0;
    vector<bool> same;
    for (int i = a; i <= b; i++)
    {
        if ((i % x) % y != (i % y) % x)
        {
            count++;
        }
        //cout << (i % x) % y << ' ' << (i % y) % x << '\n';
    }
    cout << count  << endl;

}