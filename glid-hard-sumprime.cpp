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

    bool prime[10001];
    memset(prime, 1, sizeof(prime));

    for (int i = 2; i * i <= 10000; i++)
    {
        if (prime[i])
        {
            for (int j = i*i; j <= 10000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    while (n--)
    {
        ll ans = 0;
        int x;
        cin >> x;
        for (int i = 2; i < x; i++)
        {
            if (prime[i])
            {
                ans += i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}