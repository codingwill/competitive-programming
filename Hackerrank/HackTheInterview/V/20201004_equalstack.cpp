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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a1(n1), a2(n2), a3(n3);
    ll total[4] = {0, 0, 0, 0};
    for (int i = 0; i < n1; ++i)
    {
        cin >> a1[i];
        total[1] += a1[i];
    }
    
    for (int i = 0; i < n2; ++i)
    {
        cin >> a2[i];
        total[2] += a2[i];
    }
    for (int i = 0; i < n3; ++i)
    {
        cin >> a3[i];
        total[3] += a3[i];
    }
    
    reverse(a1.begin(), a1.end());
    reverse(a2.begin(), a2.end());
    reverse(a3.begin(), a3.end());
    while (true)
    {
        if (total[1] == total[2] && total[2] == total[3]) break;
        if (a1.size() == 0 || a2.size() == 0 || a3.size() == 0) break;
        if (total[1] - a1.back() >= total[2] - a2.back() && total[1] - a1.back() >= total[3] - a3.back())
        {
            //cout << a1.back() << '\n';
            total[1] -= a1.back();
            a1.pop_back();
        }
        else if (total[2] - a2.back() >= total[1] - a1.back() && total[2] - a2.back() >= total[3] - a3.back())
        {
            //cout << 't' << '\n';
            total[2] -= a2.back();
            a2.pop_back();
        }
        else if (total[3] - a3.back() >= total[1] - a1.back() && total[3] - a3.back() >= total[2] - a2.back())
        {
            total[3] -= a3.back();
            a3.pop_back();
        }
    }
    cout << total[1] << '\n';
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