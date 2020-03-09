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
const int MAX = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    if (s[0] != 'h' || s.length() % 2 == 1)
    {
        puts("No");
        return 0;
    }
    for (int i = 0; i < s.length(); i+=2)
    {
        if (!(s[i] == 'h' && s[i+1] == 'i'))
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}