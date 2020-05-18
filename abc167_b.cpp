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
    int a, b, c, k;
    int a2, b2, c2;
    cin >> a >> b >> c >> k;
    a2 = (a >= k ? k : a);
    k -= (a >= k ? k : a);
    if (k == 0)
    {
        cout << a2 << '\n';
        //cout << "t";
        return 0;
    }
    b2 = (b >= k ? k : b);
    k -= (b >= k ? k : b);
    if (k == 0)
    {
        cout << a2 << '\n';
        return 0;
    }
    c2 = (c >= k ? k : c);
    k -= (c >= k ? k : c);
    cout << a2 - c2 << '\n';
    
}