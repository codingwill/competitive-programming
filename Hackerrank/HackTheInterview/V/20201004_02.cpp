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
    vector<int> a(26, 0);
    vector<bool> skip(26, false);
    int maks = 0;
    int count = 0;
    char kombinasi[2];
    string terpilih;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i <= (int)'z'; ++i)
    {
        for (int j = 0; j <= (int)'z'; ++j)
        {
            if (i == j) continue;
            char a, b;
            a = 'a' + i;
            b = 'a' + j;
            kombinasi[0] = a;
            kombinasi[1] = b;
            count = 0;
            bool start = false;
            int index;
            for (int k = 0; k < s.length(); ++k)
            {
                if (!start)
                {
                    if (s[k] == kombinasi[0])
                    {
                        start = true;
                        index = 1;
                        count++;
                    }
                    else if (s[k] == kombinasi[1])
                    {
                        start = true;
                        index = 0;
                        count++;
                    }
                }
                else
                {
                    if (s[k] == kombinasi[index])
                    {
                        index++;
                        index %= 2;
                        count++;
                    }
                    else if (s[k] == kombinasi[(index + 1) % 2])
                    {
                        count = 0;
                        break;
                    }
                }
            }
            if (maks <= count)
            {
                terpilih = a;
                terpilih += b;
            }
            maks = max(maks, count);
        }
    }
    cout << maks << '\n';
    //cout << terpilih << '\n';
    //cout << 't' << '\n';
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