#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int MAXN = 300050;
ll BIG = 1e18 + 1;
ll MOD = 998244353;
int M = 998244353;
int kiri = 0, kanan = 0;
void solve();
vector<ll> inv(MAXN, 1), fac(MAXN, 1);
 
ll fastpow(ll x, ll y, ll n = M) 
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
 
bool sortPairFirst(pair<ll, ll> &a, pair<ll, ll> &b)
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

ll combin(ll n, ll k)
{
    if (k > n) return 0;
    ll ans = fac[n];
    ans = (ans * inv[n - k]) % MOD;
    ans = (ans * inv[k]) % MOD;
    
    return ans;
}

void preCombin()
{
    ll factorial = 1;
    fac[0] = 1;
    inv[0] = 1;

    for (int i = 1; i < MAXN; ++i) 
    {
        factorial = (factorial * i) % MOD;
        fac[i] = factorial;
        inv[i] = fastpow(fac[i], MOD-2);
    }
}

ll mod(ll a, ll b)
{
    return (a % b + b) % b;
}

/*================ SOLUTION ================*/

vector<int> countA(27, 0), countB(27, 0);
vector<int> a, b;
map<int, int> countAkhir;

bool cek(int k)
{
    for (int i = 0; i < countB.size(); ++i)
    {
        if (countA[i] >= k) return true;
    }
    return false;
}

bool mungkin2(int k)
{
    for (int i = 0; i < countA.size(); ++i)
    {
        if (countA[i] > 0 && countA[i] < k) return false;
    }
    return true;
}

bool mungkin(int k)
{
    for (int i = a.size()-1; i >= 0; --i)
    {
        if (a[i] == b[i]) continue;
        else if (a[i] > b[i]) return false;
        else
        {
            //cout << i << '\n';
            if (i - (k-1) >= 0)
            {
                int x = i - (k-1);
                if (b[x] > b[i]) return false;
                else
                {
                    i = i - (k-1);
                }
            }
            else return false;
        }
    }
    return true;
}


void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        fill(countB.begin(), countB.end(), 0);
        fill(countA.begin(), countA.end(), 0);
        a.clear(); b.clear();
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;        
        for (int i = 0; i < n; ++i)
        {
            a.push_back(s[i] - 'a');
            b.push_back(t[i] - 'a');
            countA[s[i] - 'a']++;
            countB[t[i] - 'a']++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool can = true;
        can = cek(k) && mungkin(k) && mungkin2(k);
        //cout << '\n';
        if (can) cout << "Yes\n";
        else cout << "No\n";
    }
}
 
/* ========= KOTRETAN ========= \*

1
4 2
abca
ljki

1
6 2
abbbbb
ddddcc

1
4 3
aaab
cddd
No (Harusnya Yes)

1
5
2
aabcd
bbcdd
Yes
*/