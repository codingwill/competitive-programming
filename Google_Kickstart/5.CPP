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
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
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

vector<char> code(256, '-');

void Encode()
{
    code['A'] = 'A';
    code['E'] = '3';
    code['H'] = 'H';
    code['I'] = 'I';
    code['J'] = 'L';
    code['M'] = 'M';
    code['O'] = 'O';
    code['S'] = '2';
    code['T'] = 'T';
    code['U'] = 'U';
    code['V'] = 'V';
    code['W'] = 'W';
    code['X'] = 'X';
    code['Y'] = 'Y';
    code['Z'] = '5';
    code['1'] = '1';
    code['2'] = 'S';
    code['3'] = 'E';
    code['5'] = 'Z';
    code['8'] = '8';
}

bool isPalindrome(string s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

bool isMirror(string s)
{
    string cermin = "";
    bool mirror = false;
    //cout << 't' << '\n';
    for (int i = 0; i < s.length(); ++i)
    {
        if (code[s[i]] != '-')
        {
            cermin.push_back(code[s[i]]);
        }
        else
        {
            cermin.push_back('-');
        }
    }
    //cout << cermin << '\n';
    return equal(s.begin(), s.end(), cermin.rbegin());
}

void solve()
{
    Encode();
    while (true)
    {
        string s;
        cin >> s;
        bool cermin = isMirror(s);
        bool palindrome = isPalindrome(s);
        cout << s << " -- ";
        if (palindrome)
        {
            if (cermin) cout << "palindrom refleksi";
            else cout << "palindrom biasa";
        }
        else
        {
            if (cermin) cout << "string refleksi";
            else cout << "bukan palindrom";
        }
        cout << '\n';
        if (cin.eof()) break;
    }    
}
 
/*
 
6 6
9 10 12 4 7 2
3 4 6 0 1 0
0 0 0 0

4 6 1 2 3 5 
*/