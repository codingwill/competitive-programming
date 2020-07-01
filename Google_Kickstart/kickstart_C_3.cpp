#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<char> a[r];
        set<char> himp;
        for (int i = 0; i < r; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < c; j++)
            {
                a[i].push_back(s[j]);
                himp.insert(s[j]);
            }
        }
        set<char> ground;
        for (int i = 0; i < c; i++)
        {
            ground.insert(a[r-1][i]);
        }
        if (ground.size() != himp.size())
        {
            cout << -1 << '\n';
            ground.clear();
            himp.clear();
            continue;
        }
        set<char> urutan;
        string ans = "";
        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                if (urutan.find(a[j][i]) == urutan.end())
                {
                    ans += a[j][i];
                }
                urutan.insert(a[j][i]);
            }
        }
        cout << ans << '\n';
    }
}
