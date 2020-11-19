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
    int g;
    cin >> g;
    while (g--)
    {
        int b, k;
        cin >> b >> k;
        vector<vector<char>> a(b, vector<char>(k));
        for (int i = 0; i < b; ++i)
        {  
            string s;
            cin >> s;
            for (int j = 0; j < k; ++j)
            {
                a[i][j] = s[j];
            }
        }
        ll ans = 0;
        for (int i = 0; i < b; ++i)
        {  
            for (int j = 0; j < k; ++j)
            {
                if (a[i][j] == 'O') continue;
                int atas = i-1;
                int bawah = i+1;
                int kanan = j+1;
                int kiri = j-1;
                while (true)
                {
                    //cout << 't' << '\n';
                    if (kiri < 0 && atas < 0 && kanan >= k && bawah >= b) break;
                    int jumlah = 0;
                    if (atas >= 0)
                    {
                        if (a[atas][j] == 'v')
                        {
                            jumlah++;
                        }
                        else if (a[atas][j] == 'O')
                        {
                            atas = -2;
                        }
                        atas--;
                    }
                    if (bawah <= b-1)
                    {
                        if (a[bawah][j] == '^')
                        {
                            jumlah++;
                        }
                        else if (a[bawah][j] == 'O')
                        {
                            bawah = b;
                        }
                        bawah++;
                    }
                    if (kanan <= k-1)
                    {
                        if (a[i][kanan] == '<')
                        {
                            jumlah++;
                        }
                        else if (a[i][kanan] == 'O')
                        {
                            kanan = k;
                        }
                        kanan++;
                    }
                    if (kiri >= 0)
                    {
                        if (a[i][kiri] == '>')
                        {
                            jumlah++;
                        }
                        else if (a[i][kiri] == 'O')
                        {
                            kiri = -2;
                        }
                        kiri--;
                    }
                    ans += Combin(jumlah, 2);
                }
            }

        }
        cout << ans << '\n';
    }
}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 
*/