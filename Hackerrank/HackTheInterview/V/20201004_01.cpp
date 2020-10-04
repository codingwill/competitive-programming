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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string special = "!@#$%^&*()-+";
    int count = 0;
    vector<bool> condition(4, false);
    for (int i = 0; i < s.length(); ++i)
    {
        if ((int)s[i] >= '0' && (int)s[i] <= '9')
        {
            condition[0] = true;
        }
        if ((int)s[i] >= 'a' && (int)s[i] <= 'z')
        {
            condition[1] = true;
        }
        if ((int)s[i] >= 'A' && (int)s[i] <= 'Z')
        {
            condition[2] = true;
        }
        for (int j = 0; j < special.size(); ++j)
        {
            if (special[j] == s[i]) condition[3] = true;
        }
    }
    for (int i = 0; i < condition.size(); ++i)
    {
        if (!condition[i]) count++;
    }
    if (n < 6) cout << max(count, 6 - n) << '\n';
    else cout << count << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}


 
/*

*/