#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/11/29
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
int m = 998244353;
int kiri = 0, kanan = 0;
void solve();
 
ll fastpow(ll x, ll y, ll n = m) 
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


bool stringSort(string &a, string &b)
{
    if (a.length() > b.length()) return a.length() > b.length();
    return a > b;
}

void binsearch(int n, int x)
{
    int left = 0;
    int right = n;
    while (left < right)
    {
        int middle = (left + right) / 2;
        //cout << middle << '\n';
        //if (middle == x) break;
        if (middle <= x)
        {
            left = middle + 1;
            if (x != middle) kiri++;
        }
        else
        {
            right = middle;
            kanan++;
        }
    }
}

int sequence(int a, int b)
{
    ll res = 1; 
    for (ll i = b; i <= a; i++) 
        res = (res * i) % MOD; 
    return res; 
}

/*================ SOLUTION ================*/
void solve()
{
    int n, m;
    cin >> n;
    vector<int> harga(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> harga[i];
    }
    cin >> m;
    vector<pair<int, int>> bidder(m);
    for (int i = 0; i < m; ++i)
    {
        int input;
        cin >> input;
        bidder[i] = make_pair(input, i);
    }
    sort(bidder.begin(), bidder.end(), sortPairFirstDec);
    int ans = 0;
    int j = 0, i = 0;
    int prevIndex = -1;
    vector<bool> udah(n, false);
    while (i < n && j < m)
    {
        int bid = bidder[j].first;
        int index = bidder[j].second;
        if (bid >= harga[i])
        {
            if (i == 0 && j == 0) 
            {
                j++;
                ans++;
                udah[i] = true;
                prevIndex = index;
            }
            else
            {
                if (!udah[i]) 
                {
                    udah[i] = true;
                    ans++;
                    prevIndex = 1e6;
                    cout << i << ' ' << j << '\n';
                }
                if (index > prevIndex)
                {
                    i++;
                }
                else
                {
                    j++;
                    prevIndex = bidder[j-1].second;
                }
            }
        }
        else
        {
            i++;
        }
    }
    cout << ans << '\n';
}
 
/* ========= KOTRETAN ========= \*

4
1000 1000 1000 1000
4
3000 2000 2500 1000
3

1000 1000 1000 1000
3000 2500 2000 1000
  1    3    2   4


10 40 30 50 20
50 15 10 5
2  4  3  1

4
1000 1500 1000 1000
4
3000 1000 2500 1000
4

1000 1500 1000 1000
3000 2500 1000 1000
  1    3    2    4

1000 1000 1000 1500
  1    3    4    2
3000 -> 1
1000 -> 3
2500 -> 2


4
1000 1000 1000 1000
4
3000 2000 2500 1000

3000 2500 2000 1000
  1    3    2    4
 
*/