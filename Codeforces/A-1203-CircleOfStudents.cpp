#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        bool bisa = true;
        int n;
        cin >> n;
        int before;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            if (i == 0) before = input;
            else if (i < n-1)
            {
                if (!(abs(before-input) == 1 || abs(before-input) == n-1))
                {
                    bisa = false;
                }
            }
            before = input;
        }
        if (bisa) cout << "YES" << '\n';
        else cout << "NO" << '\n';   
    }
    return 0;
}