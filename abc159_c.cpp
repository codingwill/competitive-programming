#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
//TIPE DATA BENTUKAN
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;


bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}


int fact(int n)
{
    if (n <= 0) return 1;
    return n * fact(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double l;
    cin >> l;
    cout << fixed << setprecision(6) << (l/3) * (l/3) * (l/3) << endl;
    
    return 0;
}
/*
4
1 2 1 = 2
3 1 1 = 3
1.33 1.33 1.33 = 
3.8 0.1 0.1 =
*/