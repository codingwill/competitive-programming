#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;
ll dp[105];
ll q[105], a[105];

void solve(string s, int n)
{
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            int ruasKiri = 0, ruasKanan = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == i) continue;
                if (j < i && s[j] == 'Q') ruasKiri++;
                else if (s[j] == 'Q') ruasKanan++;
            }
            count += (ruasKiri * ruasKanan);
        }
    }
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int len = s.length();
    solve(s, len);
    return 0;
}