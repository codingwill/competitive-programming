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
        int n;
        cin >> n;
        vector<int> s(n), dp(n+5, 0);
        ll maks = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            ll temp = 0;
            for (int j = 0; j * j <= i; j++)
            {
                if ((i+1) % (j+1) == 0 && s[j] < s[i])
                {
                    temp++;
                }
            }
            maks = max(maks, temp);
        }
        cout << maks << '\n';
    }
}
/*
+ (k-1) * 2
5 6
f(5) = 5, 5 + 5 = 10
f(10) = 2, 10 + 2 = 12
f(12) = 2, 12 + 2 = 14

9 4
3, 9 + 3 = 12
7, 7 + 7 = 14

*/