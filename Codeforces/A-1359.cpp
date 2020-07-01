#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std
//AUTHOR'S NAME
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int sisaJoker = m - (n/k);
        int ans;
        if (m > n/k)
        {
            ans = n/k - ceil((float)sisaJoker / (float)(k-1));
            //cout << m << ' ' << ceil((float)sisaJoker / (k-1));
        }
        else
        {
            ans = m;
        }
        cout << ans << '\n';
        
    }
}
/*
12 7 3
sisa = 3
dist = sisa / (k-1)
[4] 1 1

12 8 4
3 3 3 3
3 11 11 1 
*/