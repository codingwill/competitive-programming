#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int generateGCD(int a, int b, int c)
{
    return __gcd(a, __gcd(b, c));
}

int a[201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    int ans = 0;
    //generate gcd sum
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                ans += generateGCD(i, j, k);
                //cout << generateGCD(i, j, k) << '\n';
            }
        }
    }
    cout << ans << '\n';
    /*
    
    111 = 1 1 = 1
    112 = 1 1 = 1
    121 = 1 1 = 1
    122 = 1 2 = 1
    211 = 1 1 = 1
    212 = 1 1 = 1
    221 = 2 1 = 1
    222 = 2 2 = 2
    */
    //cout << __gcd(2, 1) << endl;
    return 0;
}
