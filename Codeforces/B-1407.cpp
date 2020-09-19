#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/06
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 998244353;

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

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> used(n, false);
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            a[i] = input;
        }
        sort(a.begin(), a.end(), greater<int>());
        int base = 0;
        used[base] = true;
        cout << a[base] << ' ';
        int index = 0;
        int FPB = a[base];
        int maks = a[base];
        int prev = a[base];
        vector<int> ans;
        ans.push_back(a[n-1]);
        for (int j = 0; j < n-1; ++j)
        {
            bool first = true;
            FPB = -1;
            for (int i = 0; i < n; ++i)
            {
                if (!used[i])
                {
                    if (__gcd(a[i], prev) > FPB)
                    {
                        FPB = __gcd(a[i], prev);
                        maks = a[i];
                        index = i;
                        //cout << FPB << ' ';
                    }
                }
            }
            //cout << FPB << '\n';
            used[index] = true;
            prev = __gcd(prev, a[index]);
            cout << maks << ' ';
        }
        cout << '\n';
        

        
    }
    
}
/*
64 25 75 100 50

25 50 64 75 100
100 50 25 75 64



6
96 128 88 80 52 7
7 
*/