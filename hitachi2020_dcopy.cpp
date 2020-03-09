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

bool tupleSort1(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
    return get<1>(a) < get<1>(b);
}

bool tupleSort2(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    if (get<2>(a) == get<2>(b)) return get<1>(a) < get<1>(b);
    return get<2>(a) < get<2>(b);
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
    int N;
    double T;
    cin >> N >> T;
    double time = 0;
    vector<tuple<int, int, int>> shop, shop2;
    map<int, bool> visited;
    int aPoint = 0, bPoint = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        shop.push_back(make_tuple(i, a, b));
        shop2.push_back(make_tuple(i, a, b));
    }
    sort(shop.begin(), shop.end(), tupleSort1);
    sort(shop2.begin(), shop2.end(), tupleSort2);
    /*
    cout << "==========" << endl;
    for (int i = 0; i < shop.size(); i++)
    {
        cout << get<1>(shop2[i]) << " " << get<2>(shop2[i]) << endl;
    }
    */
    int i;
    for (i = 0; i < N; i++)
    {
        ++time;
        while (visited[get<0>(shop[aPoint])])
        {
            aPoint++;
        }
        while (visited[get<0>(shop2[bPoint])])
        {
            bPoint++;
        }

        int a = (time * get<1>(shop[aPoint])) + get<2>(shop[aPoint]);
        int b = (time * get<1>(shop2[bPoint])) + get<2>(shop2[bPoint]);
        cout << "a = " << a << ", b = " << b << endl;
        if (a < b)
        {
            visited[get<0>(shop[aPoint])] = true;
        }
        else if (a > b) 
        {
            visited[get<0>(shop2[bPoint])] = true;
        }
        else
        {
            visited[get<0>(shop2[bPoint])] = true;
            visited[get<0>(shop[aPoint])] = true;
        }

        time += min(a, b);
        cout << "Waktu : " << time << endl;
        if (time > T + 0.5) break;
        //cout << "t" << endl;
    }

    cout << i << '\n';
    return 0;
}

/*
3 7 = 7.5
travel = 1 = 1
store 1 = 1 x 2 + (0) = 2
travel = 1 = 3
store 3 = 3 x 0 + 3 = 6 

*/