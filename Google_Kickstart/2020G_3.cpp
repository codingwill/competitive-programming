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

ll mod(ll a, ll b)
{
    if (a % b == 0) return b;
    return a % b;
}

void solve()
{
    int t;
    cin >> t;
    int total = t;
    while (t--)
    {
        ll w, n;
        cin >> w >> n;
        ll ans = INT64_MAX;
        vector<ll> a(w, 0);
        for (int i = 0; i < w; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<ll> sum(w, 0);
        sum[0] = a[0];
        //cout << sum[0] << ' ';
        for (int i = 1; i < w; ++i)
        {
            sum[i] = sum[i-1] + a[i];
            //cout << sum[i] << ' ';
        }
        //cout << endl;
        for (int i = 0; i < w; ++i) //O(N)
        {
            ll total = 0;
            if (a[i] + n/2 > a[w-1])
            {
                auto it = upper_bound(a.begin(), a.end(), mod(a[i] + n/2, n)); //O(log^2(N)
                int index = it - a.begin();
                cout << "index: " << index << '\n';
                if (index > 0 && index != w) 
                {
                    index--;
                    int count = (index + 1);
                    total += sum[index];
                    total -= (i * n) - (sum[index-1] - (index * a[i]));
                }
                int count = (w - i);
                total -= (count * a[i]);
                total += sum[w-1];
                cout << total << '\n';
                if (i > 0) 
                {
                    total -= sum[i-1];
                    total += ((i * a[i]) - sum[i-1]);
                }
            } 
            else
            {
                auto it = upper_bound(a.begin(), a.end(), a[i] + n/2); //O(log^2(N)
                int index = it - a.begin();
                int count = (index - i);
                total -= (count * a[i]);
                total += sum[index-1];
                if (i > 0)
                {
                    total -= sum[i-1];
                    total += (i * n) - (sum[i-1] - (i * a[i]));
                }
            }
            cout << total << '\n';
            ans = min(total, ans);
            
        }
        cout << "Case #" << total - t << ": " << ans; 
        cout << '\n';
    }
}
 
/*
1
4 10
2 9 3 8

2 3 8 9
2 5 13 22
9 


2 3 4
1 1 1

2 3 5 8 9
1 2 3 1 3
8 4 2 4 10

5
0 0 0 1 0
0 0 0 1 1
0 0 1 1 1
1 1 1 1 1
15 1 1 1 1
*/