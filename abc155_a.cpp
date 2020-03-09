#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
int main()
{
    int a[3];
    for (int i = 0 ; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a, a+3);
    if (((a[0] == a[1]) && (a[1] != a[2])) || ((a[0] != a[1]) && (a[1] == a[2])))
    {
        cout << "Yes" << '\n';

    }
    else
    {
        cout << "No" << endl;
    }
    
}