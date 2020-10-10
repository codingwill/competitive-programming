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
    int p;
    cin >> p;
    while (p--)
    {
        string s;
        cin >> s;
        list<char> ans;
        list<char>::iterator it = ans.begin();
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '<')
            {
                if (it != ans.end())it++;
            }
            else if (s[i] == '>')
            {
                if (it != ans.begin()) it--;
            }
            else if (s[i] == '-')
            {
                if (it != ans.end()) it = ans.erase(it);
            }
            else
            {
                ans.insert(it, s[i]);
                it--;
            }
            /*
            for (auto n : ans)
            {
                cout << n;
            }
            cout << '\n';
            */
        }
        string ansStr;
        for (auto n : ans)
        {
            ansStr.push_back(n);
        }
        reverse(ansStr.begin(), ansStr.end());
        //cout << 't' << '\n';
        cout << ansStr << '\n';
    }
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