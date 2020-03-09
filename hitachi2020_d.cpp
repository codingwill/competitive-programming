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

bool pairSortFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool pairSortSecond(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

using ll = long long int;
const int MAX = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, T;
    cin >> N >> T;
    ll time = 1;
    vector<pair<int, int>> shop, shop2;
    int aPoint = 0, bPoint = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        shop.push_back(make_pair(a, b));
        shop2.push_back(make_pair(a, b));
    }
    sort(shop.begin(), shop.end(), pairSortFirst);
    sort(shop2.begin(), shop2.end(), pairSortSecond);
    int i;
    for (i = 0; i < N; i++)
    {
        if (time < T) break;
        time += min((time * shop[aPoint].first) + shop[aPoint].second, (time * shop2[bPoint].first) + shop2[bPoint].second);
    }

    cout << time << '\n';
    return 0;
}

/*
3 7 = 7.5
travel = 1 = 1
store 1 = 1 x 2 + (0) = 2
travel = 1 = 3
store 3 = 3 x 0 + 3 = 6 

*/