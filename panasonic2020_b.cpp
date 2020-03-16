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
    ll h, w;
    cin >> h >> w;
    if (h == 1 || w == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    cout << (ll) ceil((double)(h * w) / 2) << endl;
    return 0;
}
//500000000000000000
//500000000000000000