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
    ll a, b, c;
    cin >> a >> b >> c;
    //cout << setprecision(10) << pow(a, 0.5) + pow(b, 0.5) << ' ' << pow(c, 0.5) << '\n';
    //cout << setprecision(10) << sqrt(a) + sqrt(b) << ' ' << sqrt(c) << '\n';
    //cout << sqrt(a) + sqrt(b) << ' ' << sqrt(c) << endl;
    //cout << a + b + sqrt(a * b) << ' ' << c << endl;
    //a + b + 2 * sqrt(a * b) < c ? cout << "Yes" : cout << "No";
    //2 * sqrt(a * b) < c - a - b
    (c - a - b > 0 && 4 * a * b < (c - a - b) * (c - a - b)) ? cout << "Yes" : cout << "No";
    return 0;
}
//3774506968