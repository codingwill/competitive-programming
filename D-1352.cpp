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
        int l = 1, r = n-1;
        int move = 1;
        int al, bob = 0;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        al = a[0];
        ll befCandy = a[0];
        int i = 0;
        while (l <= r)
        {
            ll candy = 0;
            if (move % 2 == 0) //alice
            {
                move++;
                while (candy <= befCandy)
                {
                    if (l > r) break;
                    al += a[l];
                    candy += a[l];
                    l++;
                }
                befCandy = candy;
            }
            else
            {
                move++;
                while (candy <= befCandy)
                {
                    if (l > r) break;
                    bob += a[r];
                    candy += a[r];
                    r--;
                }
                befCandy = candy;
            }
        }
        cout << move << ' ' << al << ' ' << bob << '\n';
    }
}