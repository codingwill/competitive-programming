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
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0) a.push_back(i);
            else b.push_back(i);
        }
        if (n < 4) 
        {
            cout << "-1" << '\n';
            continue;
        }
        if (n % 2 == 0)
        {
            reverse(b.begin(), b.end());
            swap(b[1], b[0]);
            for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
            for (int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
        }
        else
        {
            reverse(a.begin(), a.end());
            swap(a[1], a[0]);
            for (int i = 0; i < b.size(); ++i) cout << b[i] << ' ';
            for (int i = 0; i < a.size(); ++i) cout << a[i] << ' ';
        }
        cout << '\n';
    }
}