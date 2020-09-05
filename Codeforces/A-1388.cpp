#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

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
        if (n < 2*3 + 2*5 + 2*7 + 1)
        {
            cout << "NO\n";
        }
        else if (n == 36)
        {
            cout << "YES" << '\n';
            cout << "5 6 10 15" << '\n';
        }
        else if (n == 40)
        {
            cout << "YES" << '\n';
            cout << "5 6 14 15" << '\n';
        }
        else if (n == 44)
        {
            cout << "YES" << '\n';
            cout << "6 10 13 15" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            cout << n - 30 << ' ' << "6 10 14" << '\n';
            
        }
        
    }
    //for (int i = 0; i < 10; i++) cout << primeList[i] << endl;
    
}

/*
2 3 6
2 5 10
2 7 14
30
36
40
44
*/