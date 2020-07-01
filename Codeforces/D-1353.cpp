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
        vector<int> a(n);
        int l = 1, r = n;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if ((r-l+1) % 2 == 1)
                {
                    a[(l+r)/2 - 1] = (i+1);
                }
                else
                {
                    a[(l+r-1)/2 - 1] = (i+1);
                }
            }
            else
            {
                
            }
            
        }
    }
}