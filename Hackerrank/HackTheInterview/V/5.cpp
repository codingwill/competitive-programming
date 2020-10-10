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
string s, s2;

string convert(ll x, ll y, ll n) 
{ 
    s2 = "";
    if (y == 0) 
    { 
        cout << "Infinite" << endl; 
        return ""; 
    } 
    if (x == 0) 
    { 
        return "0"; 
    } 
    if (n <= 0) 
    {  
        return to_string(x/y); 
    } 
  
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) 
    { 
        cout << "-"; 
        x = x > 0 ? x : -x; 
        y = y > 0 ? y : -y; 
    } 
  
    ll d = x / y; 
  
    for (int i = 0; i <= n; i++) 
    { 
        s2 += to_string(d); 
        x = x - (y * d); 
        if (x == 0) 
            break; 
        x = x * 10; 
        d = x / y; 
        if (i == 0) s2 += "."; 
    } 
    //cout << s << '\n';
    return s2;
} 

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n, p;
        cin >> a >> b >> n >> p;
        s = convert(a, b, n);
        //cout << s << '\n';
        reverse(s.begin(), s.end());
        int len = s.length();
        for (int i = len-1; i >= 0; --i)
        {
            if (s[i] == '.') 
            {
                s.pop_back();
                break;
            }
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        len = s.length();
        if (len < n)
        {
            int len = s.length();
            for (int i = 0; i < n - len; ++i)
            {
                s.push_back('0');
            }
        }
        //cout << s << '\n';
        ll ans = 0;
        if (p == 2)
        {
            for(int i = n; i > 0; --i) 
            {
                if((s[i-1] - '0') % 2 == 0) ans += i;
            }
            cout << ans << "\n";
            continue;
        }
        else if (p == 5)
        {
            for(int i = n; i > 0; i--)
            {
                if((s[i-1] - '0') % 5 == 0) ans += i;
            }
            cout << ans << "\n";
            continue;
        }

        vector<ll> arr(1000005, 0);
        ll temp = 0;
        ll x = 1;
        arr[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            temp = (temp + (s[n-i-1] - '0') * x) % p;
            arr[temp]++;
            x = x * 10 % p;
        }

        for (int i = 0; i < p; ++i)
        {
            if (arr[i] > 0) ans += arr[i] * (arr[i] - 1) / 2;
        }

        cout << ans << '\n';
    }
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
