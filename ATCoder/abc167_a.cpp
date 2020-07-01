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
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}