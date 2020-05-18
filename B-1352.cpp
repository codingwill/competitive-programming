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
        int n, k;
        cin >> n >> k;

        if (((n - (k-1)) % 2 == 0 && k*2 > n) || k > n)
        {
            cout << "NO" << '\n';
            continue;
        }
        //ganjil
        if (n % 2 == 1 && k % 2 == 1)
        {
            cout << "YES" << '\n';
            for (int i = 0; i < k-1; i++)
            {
                cout << n / k << ' ';
            }
            cout << n - (n/k) * (k-1) << '\n';
        } 
        else if (n % 2 == 0 && k % 2 == 0)
        {
            cout << "YES" << '\n';
            for (int i = 0; i < k-1; i++)
            {
                cout << n / k << ' ';
            }
            cout << n - (n/k) * (k-1) << '\n';
        }
        else if (n % 2 == 0 && k % 2 == 1)
        {
            cout << "YES" << '\n';
            for (int i = 0; i < k-1; i++)
            {
                cout << ((n / k) % 2 == 1 ? (n/k) - 1 : n/k) << ' ';
            }
            cout << n - ((n / k) % 2 == 1 ? (n/k) - 1 : n/k) * (k-1) << '\n';
        }
        else if (n % 2 == 1 && k % 2 == 0)
        {
            cout << "NO" << '\n';
        }
    }
}

/*
if (n % 2 == 1)
        {
            cout << "YES" << '\n';
            for (int i = 0; i < k-1; i++)
            {
                cout << n / k << ' ';
            }
            cout << n % k << '\n';
            continue;
        }
        //genap
        else
        {
            if (n % k == 1)
            {
                if (k * 2 <= n)
                {
                    cout << "YES" << '\n';
                    for (int i = 0; i < k-1; i++)
                    {
                        cout << (int)ceil((float)n / k) << ' ';
                    }
                    cout << n - (int)ceil((float)n / k) * (k-1) << '\n';
                    continue;
                }
                else
                {
                    cout << "NO" << '\n';
                }
            }
            
        }
*/