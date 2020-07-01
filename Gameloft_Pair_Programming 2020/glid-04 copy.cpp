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

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans;
        bool ada = false;
        for (int i = 0; i < s.length()-1; i++)
        {
            for (int j = 1; j < s.length()-i; j++)
            {
                if (s.substr(i, j) == s.substr(i+j, j))
                {
                    ans = s.substr(i, j);
                    ada = true;
                    break;
                }
            }
            if (ada) break;
        }
        if (ada)
            cout << ans << '\n';
        else
            cout << s << '\n';
    }
}