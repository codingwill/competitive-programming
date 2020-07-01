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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];      
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        ll count = 0; 
        for (int i = 0; i < n; i++)
        {
            if (i < k)
            {
                if (a[i] < b[(n-1)-i])
                {
                    count += b[(n-1)-i]; 
                }
                else
                {
                    count += a[i];
                }
                
            }
            else
            {
                count += a[i];
            }
            
        }
        cout << count << '\n';
    }
}
