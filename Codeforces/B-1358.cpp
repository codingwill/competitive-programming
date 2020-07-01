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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int maks = -1;
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            maks = max(maks, a[i]);
            if (i+1 >= maks) ans = i+2;
        }
        cout << ans << '\n';
        a.clear();
    }
}