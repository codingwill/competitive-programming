#include <bits/stdc++.h>
 
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
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 1; i*i <= n; i++)
        {
            if (n % i == 0 && n != 1)
            {
                sum += i;
                if (i != 1 && i*i != n)
                sum += n / i;
            }
        }
        cout << sum << '\n';
    }
}
