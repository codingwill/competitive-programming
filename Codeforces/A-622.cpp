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
    ll n;
    cin >> n;
    for (ll i = (ll)sqrt(n*2)-1; i <= (ll)sqrt(n*2)+1; i++)
    {
        if (i*i + i > n * 2)
        {
            i--;
            cout << n - (i*i + i)/2 << endl;
            return 0;
        }
        else if (i*i + i == n * 2)
        {
            cout << i << endl;
            return 0;
        }
    }
}
/*
1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5, ...
1 3 6 10 15 21 28 36 45 55 76 88 101 ...
1 2 3 4 5 6 7 8 9 10 11 12 13 ...
keyboardku rusak 

1 - - - -
1 2 - - -
1 2 3 - -
1 2 3 4 -
1 2 3 4 5


1 2 3 4 5
5 4 3 2 1
6 6 6 6 6

(last*(1+last))/2 (DERET ARITMATIKA XD)

(10*(10+1))/2 = 55
55 = (x*x + x) / 2
55 * 2 = x * (x+1)
110 = x*x + x
approx sqrt(110)-1 ~ sqrt(110)+1 (complete search O(3) *brute force but constant? hmm xD...)
*/