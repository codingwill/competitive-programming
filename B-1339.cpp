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
        vector<int> a;
        deque<int> ans;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        sort(a.begin(), a.end());
        int l = 0, r = n-1;
        int i = 1;
        while (true)
        {
            ans.push_front(a[l]);    
            l++;
            if (n % 2 == 1)
            {
                if (l == (n+1)/2) break;
            }
            ans.push_front(a[r]);
            r--;
            if (n % 2 == 0)
            {
               if (l == n/2) break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans.front();
            if (!ans.empty()) ans.pop_front();
            if (i != n-1) cout << ' ';
        }
        cout << '\n';
    }
}
/*

sek kuliah online ._.
6
5 -2 4 8 6 5
-2 4 5 5 6 8
5 5 6 4 8 -2
*/
