#include <bits/stdc++.h>
 
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
    int t;
    cin >> t;
    string ans[t];
    for (int z = 0; z < t; z++)
    {
        string a;
        char b;
        cin >> a >> b;
        while (a.length() > 1)
        {
            int temp = 0;
            for (int i = 0; i < a.length(); i++)
            {
               temp += (a[i] - '0');
            }
            a = to_string(temp);
        }
        if (a[0] - '0' == (b-'A') + 1) ans[z] = "match";
        else ans[z] = "error";
    }
    for (string n : ans) cout << n << '\n';
}