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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int start = k;
        while (start > 2 && (start/2) % 2 == 0)
        {
            start /= 2;
        }
        
        
        bool yes = false;
        while (start <= k)
        {
            //cout << start << '\n';
            vector<int> dp;
            string pencocok;
            bool change = true;
            ll count = 0;
            for (int i = 0; i < n; ++i)
            {
                if (change)
                {
                    count++;
                    pencocok.push_back('1');
                }
                else
                {
                    count++;
                    pencocok.push_back('0');
                }
                if (count == start/2)
                {
                    count = 0;
                    change = !change;
                }
            }
            bool can = true;
            for (int i = 0; i < start/2; ++i)
            {
                int way = 0;
                for (int k = 0; k < 2; ++k)
                {
                    int state = k;
                    bool possible = true;
                    for (int j = i; j < n; j += start/2)
                    {
                        //cout << s[j] - '0' << ' ' << state << '\n';
                        if (s[j] - '0' != state && s[j] != '?')
                        {
                            //cout << j << " " << dp[j] << '\n';
                            possible = false;
                        }
                        state = (state + 1) % 2;
                    }
                    if (possible)
                    {
                        way++;
                    }
                }
                if (way == 0) can = false;
            }
            if (can)
            {
                yes = true;
                break;
            }
            start *= 2;
            //cout << '\n';
        }
        if (yes) cout << "YES\n";
        else cout << "NO\n";
    }
    
}
/*
100110
110011
010101


1?0??1?
1001010 NO
1001100 YES
1100110 YES


111000111000
100011100011

111000111000
101010101010
110001110001
100011100011
1100110011001100

*/
