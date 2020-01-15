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

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s[n], t[m];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int y;
        cin >> y;
        cout << s[(y-1) % n] + t[(y-1) % m] << '\n';
    }

}