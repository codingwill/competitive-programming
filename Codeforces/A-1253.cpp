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
        vector<int> a, b;
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        int left = 0, right = 0;
        int iLeft = 0, iRight = 0;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            b.push_back(input);
            if (input - a[i] < 0)
            {
                can = false;
                continue;
            }
            if (left == 0)
            {
                if (input - a[i] > 0)
                {
                    left = input - a[i];
                    iLeft = i;
                }
            }
        }
        if (can)
        {
            for (int i = n-1; i >= 0; i--)
            {
                if (right == 0)
                {
                    if (b[i] - a[i] > 0)
                    {
                        right = b[i] - a[i];
                        iRight = i;
                    }
                }
            }
            if (right == left)
            {
                for (int i = iLeft; i < iRight; i++)
                {
                    if (b[i] - a[i] != left)
                    {
                        can = false;
                        break;
                    }
                }
            }
            else
            {
                can = false;
            }
            
        }
        

        if (can) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        b.clear();
    }
}