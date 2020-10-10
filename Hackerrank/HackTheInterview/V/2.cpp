#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/10/04
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
    ll n, m;
    cin >> n >> m;
    vector<ll> pangkat(65);
    for (int i = 1; i <= 64; ++i)
    {
        if (i == 1) pangkat[i] = 1;
        else
        {
            pangkat[i] = pangkat[i-1] * 2;
        }
        
    }
    if (n == 64)
    {
        cout << "menang\n";
        return;
    }
    pangkat[n] >= m ? cout << "menang\n" : cout << "kalah\n";
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    solve();
	return 0;
}


 
/*

*/