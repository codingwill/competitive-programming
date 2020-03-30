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
    int n, m;
    cin >> n >> m;
    ll temp = 1;
    ll ans = 1;
    for (int i = n-1; i <= n; i++)
    {
        temp = temp * i;
    } 
    ans = temp / 2;
    temp = 1;
    for (int i = m-1; i <= m; i++)
    {
        temp = temp * i;
    } 
    ans += temp / 2;
    cout << ans << '\n';

    /*
    cout << fact(13) << endl;
    cout << (fact(n)/(fact(n-2)*fact(2))) << ' ' <<  (fact(m)/(fact(m-2)*fact(2))) << '\n';
    */
   return 0;
}