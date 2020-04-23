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
    int t;
    cin >> t;
    vector<string> ans;
    while (t--)
    {
        int n;
        cin >> n;
        //vector<int> p, c;
        bool possible = true;
        int prev1, prev2;
        for (int i = 0; i < n; i++)
        {
            int p, c;
            cin >> p >> c;
            if (i > 0)
            {
                if (prev1 > p || prev2 > c || abs(prev1 - p) < abs(prev2 - c) || c > p)
                {
                    possible = false;
                }
            }
            else
            {
                if (p < c) possible = false;
            }
            
            prev1 = p;
            prev2 = c;
        }
        if (!possible)
        {
            ans.push_back("NO");
            continue;
        }
        ans.push_back("YES");
    }
    for (string n : ans) cout << n << '\n';
    return 0;
}
