#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    bool zero = false;
    int len = 0;
    ll val = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        len += to_string(a[i]).length()-1;
        if (val >= 0 && val <= 1000000000000000000) val *= a[i];
        if (a[i] == 0) zero = true;
    }
    if (zero)
    {
        puts("0");
        return 0;
    }
    if (val > 1000000000000000000 || val < 0)
    {
        puts("-1");
        return 0;
    }
    cout << val << endl;
}