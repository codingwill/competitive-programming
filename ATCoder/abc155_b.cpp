#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
int main()
{
    int n;
    cin >> n;
    int a;
    bool approve = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2 == 0)
        {
            if (!(a % 3 == 0 || a % 5 == 0))
            {
                approve = false;
            }
        }
    }
    if (approve)
    {
        cout << "APPROVED" << '\n';
    }
    else
    {
        cout << "DENIED" << '\n';
    }
    


}