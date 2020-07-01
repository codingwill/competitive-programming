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
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        int count = 0;
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] != '0') count++;
        }
        cout << count << '\n';
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] != '0')
            {
                cout << (n[i] - '0') * pow(10, n.length()-i-1) << ' ';
            }
        }
        cout << '\n';
    }
}