#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/30
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

bool sortPairSecond(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairFirst(pair<int, bool> &a, pair<int, bool> &b)
{
    return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

int KPK(int n, int x) //KPK x dekat ke n
{    
    if(x > n) return x; 
    n = n + x/2; 
    n = n - (n%x); 
    return n; 
} 

void solve()
{
    
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "1 1" << '\n';
        cout << '-' << a[0] << '\n';
        cout << "1 1" << '\n';
        cout << "0" << '\n';
        cout << "1 1" << '\n';
        cout << "0" << '\n'; 
    }
    else
    {
        cout << "1 1" << '\n';
        cout << n - a[0] << '\n';
        a[0] = n;
        cout << "2 " << n << '\n';
        for (int i = 1; i < n; ++i)
        {
            ll kpk = (a[i] * n);
            cout << kpk - a[i] << ' ';
            a[i] = kpk;
        }
        cout << '\n';
        cout << "1 " << n << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << -1 * a[i] << ' ';
        }
        cout << '\n';
    }
    
    
}
/*

4
1 23 2 4
4 92 8 4
3 69

4
1 115 2 4
+3 +9 +6
4 124 8 4
        +0
4 124 8 4
-4 -124 -8 -4

*/