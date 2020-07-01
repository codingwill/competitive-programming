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
    int z = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (i != n-1)
            {
                if (a[i] > a[i-1] && a[i] > a[i+1])
                {
                    count++;
                }
            }
        }
        cout << "Case #" << z  << ": " << count << '\n';
        z++; 
    }
}