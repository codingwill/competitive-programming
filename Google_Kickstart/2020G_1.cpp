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
        string s;
        cin >> s;
        vector<int> kick(s.length(), 0);
        string temp = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'K')
            {
                for (int j = i; j < i + 4 && j < s.length(); ++j)
                {
                    temp.push_back(s[j]);
                }
                if (temp == "KICK")
                {
                    kick[i + 3] = 1;
                }
                temp = "";
            }
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (i > 0) 
            {
                if (kick[i] == 0) kick[i] = kick[i-1];
                else kick[i] = kick[i-1] + 1;
            }
        }
        temp = "";
        ll sum = 0;
        for (int i = s.length()-1; i > 0; --i)
        {
            if (temp.length() == 0)
            {
                if (s[i] == 'T')
                {
                    temp.push_back('T');
                }
            }
            else
            {
                temp.push_back(s[i]);
            }

            if (temp.length() == 5)
            {
                if (temp == "TRATS")
                {
                   sum += kick[i-1];
                }
                temp = "";
                i += 4;
            }
            
        }
        
        cout << "Case #" << total - t << ": " << sum; 
        cout << '\n';
    }
}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 
*/