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

int solve(vector<int> &a, vector<int> &b, int n) 
{ 
	int count = 0; 
	int i = 0; 
	while (i < n) 
    { 		
		if (a[i] - b[i] == 0) 
        { 
			i += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i])); 
			continue; 
		} 
		int d = a[i] - b[i]; 
        i += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i])); 
		while (i < n && a[i] - b[i] == d) 
        { 
			i += min(abs(a[i] - b[i]), 10 - abs(a[i] - b[i])); 
		} 
		count++; 
	} 
	return count;
} 

// Driver Code 
int main() 
{ 
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while (true)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> a1, a2;
        for (int i = 0; i < s1.length(); ++i)
        {
            a1.push_back(s1[i] - '0');
        }
        for (int i = 0; i < s2.length(); ++i)
        {
            a2.push_back(s2[i] - '0');
        }

        cout << solve(a1, a2, a1.size()) << '\n'; 
        
        if(cin.eof()) break;
    }
    
	return 0; 
} 
/*
00012 32190
*/