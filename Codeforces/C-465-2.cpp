#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/09/19
*/
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
int kiri = 0, kanan = 0;
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

int n, p;

string nextString(string s)
{
    int i = s.length()-1;
    s[i]++;
    while (i >= 0 && s[i]-'a' == p)
    {
        //cout << 't' << '\n';
        s[i] = 'a';
        if (i > 0) s[i-1]++;
        i--;
    }
    return s;
}

void solve()
{
    cin >> n >> p;
    string s;
    cin >> s;
    string ans = s;
    if (p < 3 && n > 2)
    {
        cout << "NO" << '\n';
        return;
    }
    for (int i = s.length()-1; i >= 0; --i)
    {
        for (int j = s[i] - 'a' + 1; j < p; ++j)
        {
            ans[i] = 'a' + j;
            if (i == 0 || ans[i] != ans[i-1])
            {
                if (ans[i] != ans[i-2] || i == 1 || i == 0)
                {
                    //cout << ans[i] << ' ' << ans[i-2] << '\n';
                    for (int k = i + 1; k < s.length(); ++k)
                    {
                        for (int l = 0; l < 3; ++l)
                        {
                            if (k >= 1 && l == ans[k-1] - 'a') continue;
                            if (k >= 2 && l == ans[k-2] - 'a') continue;
                            //cout << l << '\n';
                            ans[k] = 'a' + l; 
                            break;
                        }
                    }
                    cout << ans << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
    
}
 
/* KOTRETAN
abdc
abda
abca
adca

abcd
abda
*/