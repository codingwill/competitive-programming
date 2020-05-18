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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int l = -1, r = -1;
    int c[2] = {0, 0};
    int len = 0;
    int ans1 = -1, ans2 = -1;
    bool possible = true;
    if (n == 1) 
    {
        cout << 1 << '\n';
        return 0;
    }
    while (true)
    {
        if (r == n-1) 
        {
            break;
        }
        if (possible) 
        {
            r++;
            if (s[r] == 'a') c[0]++;
            else c[1]++;
            len++;
            if (c[1] > k) possible = false;
        }
        if (!possible)
        {
            l++;
            if (s[l] == 'a') c[0]--;
            else c[1]--;
            len--;
            if (!(c[1] > k)) possible = true;
        }
        if (possible) ans1 = max(ans1, r-l);
    }
    c[1] = 0; 
    c[0] = 0;
    r = -1; l = -1;
    possible = true;
    while (true)
    {
        if (r == n-1) 
        {
            break;
        }
        if (possible) 
        {
            r++;
            if (s[r] == 'a') c[0]++;
            else c[1]++;
            len++;
            if (c[0] > k) possible = false;
        }
        if (!possible)
        {
            l++;
            if (s[l] == 'a') c[0]--;
            else c[1]--;
            len--;
            if (!(c[0] > k)) possible = true;
        }
        if (possible) ans2 = max(ans2, r-l);
    }
    cout << max(ans1, ans2) << '\n';
}