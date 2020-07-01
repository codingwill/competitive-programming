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
    ll a[31];
    a[1] = 2;
    for (int i = 2; i <= 30; i++)
    {
        a[i] = a[i-1] + (ll)pow(2, i);
    }
    for (int n : a) cout << n << endl;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << 2 << '\n';
            continue;
        }
        cout << (a[(n/2)-1] + (ll)pow(2, n)) - (a[n-1] - a[(n/2)-1]) << '\n';
    }
    return 0;
}

/*
2 4 8 16 32 64 

(6 + 64) - (32 + 24) = 70 - 56 = 12


*/