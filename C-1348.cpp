#include<bits/stdc++.h>
// wkwkwill
#define Willy using
#define Indrayana namespace
#define Komara std
// noobly written by:
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
        string s;
        cin >> s;
        sort (s.begin(), s.end());
        if (k == 1 || n == 1)
        {
            cout << s << '\n';
            continue;
        }
        if (n - k == 0)
        {
            cout << s[n-1] << '\n';
            continue;
        }
        string ans = "";
        if (s[0] != s[k-1]) cout << s[k-1] << '\n';
        else
        {
            if (s[k] == s[n-1])
            {
                ans = s[k-1] + s.substr(k, ceil((float)s.substr(k, n-k).length() / k));
            }
            else
            {
                ans = s[k-1] + s.substr(k, n-k);
            }
            cout << ans << '\n';
        }
    }
}

/*
aaab
k = 3

*/