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
        ll n;
        cin >> n;
        
        ll count = 0;
        if (n <= 1)
        {
            cout << 0 << '\n';
            continue;
        }
        if (n % 2 == 1)
        {
            if (n == 3)
            {
                cout << 8 << '\n';
                continue;
            }
            ll ulang = (n-3)/2;
            for (int i = 0; i < ulang; i++)
            {
                count += (ulang-i+1)*((n*2) + (n-2)*2);
                n -= 2;
            }
            count += 8;
        }
        else
        {
            if (n == 2)
            {
                cout << 3 << '\n';
                continue;
            }
            ll temp = n;
            n--;
            ll ulang = (n-3)/2;
            for (int i = 0; i < ulang; i++)
            {
                count += (ulang-i+1)*((n*2) + (n-2)*2);
                n -= 2;
            }
            count += 8;
            count += (2*(temp-1)+1)*(temp/2);
        }
        
        cout << count << '\n';
        

    }
}

/*
1 = 0
2 = 3
3 = 8
4 = 
*/