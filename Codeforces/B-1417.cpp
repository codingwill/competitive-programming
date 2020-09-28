#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
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
 
bool sortPairFirst(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
bool sortPairFirstDec(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}
  
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = (res * i) % MOD; 
    return res; 
} 
  
ll Combin(ll n, ll r) 
{ 
    return fact(n) / ((fact(r) * fact(n - r)) % MOD); 
} 
 
 
bool MySort(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
 
void solve()
{
    int t;
    cin >> t;
    int total = t;
    while (t--)
    {
        int n, T;
        cin >> n >> T;
        vector<int> a(n);
        map<int, int> count;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            if (T % 2 == 1)
            {
                if (a[i] <= T/2) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            else
            {
                if (a[i] < T/2) 
                    cout << 1 << ' ';
                else if (a[i] > T/2) 
                    cout << 0 << ' ';
                else
                {
                    if (count[a[i]] % 2 == 1)
                    {
                        cout << 0 << ' ';
                        count[a[i]]--;
                    }
                    else
                    {
                        cout << 1 << ' ';
                        count[a[i]]--;
                    }
                }
                
                
            }
            
        }
        cout << '\n';
 
    }
}
 
/*
1
7 3
12 16
1 3
4 5
7 9
10 11
17 19
19 20
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0
 
4 6 1 2 3 5 
 
K = 5
1 3
4 5
5 6
6 7
7 8
8 9
*/