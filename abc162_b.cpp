#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

ll a[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int index = 2;
    a[1] = 1;
    //generate fizzbuzz
    for (int i = 2; i <= 1000000; i++)
    {
        if (!(i % 3 == 0 || i % 5 == 0))
        {
            a[index] += a[index-1] + i;
        }
        else
        {
            a[index] = a[index-1];
        }
        index++;
    }

    int n;
    cin >> n;
    cout << a[n] << '\n';
    return 0;
}