#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int c[3];
        cin >> c[0] >> c[1] >> c[2];
        sort(c, c+3);
        if (c[2] - c[1] - c[0] > 1)
        {
            cout << "No" << '\n';
        }
        else
        {
            cout << "Yes" << '\n';
        }
        
         
    }
}