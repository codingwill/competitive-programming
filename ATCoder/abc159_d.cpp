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

ll kombin(int n)
{
    return n * (n-1) / 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    vector<int> v;
    ll ans = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        m[a[i]]++;
        if (m[a[i]] == 1) v.push_back(a[i]);
    }
    /*
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    */
    //cout << "v sz = " << v.size() << '\n';
    for (int i = 0; i < n; i++) 
    {
        ans = 0;
        m[a[i]]--;
        for (int j = 0; j < v.size(); j++)
        {
            ans += kombin(m[v[j]]);
        }
        m[a[i]]++;
        cout << ans << '\n';
    }
    //cout << m[2] << endl;
    return 0;
}
/*
4
1 2 1 = 2
3 1 1 = 3
1.33 1.33 1.33 = 
3.8 0.1 0.1 =
*/