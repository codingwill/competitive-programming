#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    while (true)
    {
        int divisible = ((a/1000) + (a%1000/100) + (a%100/10) + (a%10)) % 4;
        if (divisible == 0)
        {
            break;
        }
        a++;
    }
    cout << a << '\n';
    return 0;
}