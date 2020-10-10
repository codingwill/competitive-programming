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

int k = 3;

void solve(vector<int> &d, vector<int> &b)
{
    vector<int> diff1, diff2;
    //cout << d.size() << '\n';
    for (int i = 0; i < d.size(); ++i)
    {
        if (d[i] < b[i]) diff1.push_back(abs(d[i] - b[i]));
        else if (d[i] == b[i]) diff1.push_back(0);
        else diff1.push_back(10 - abs(d[i] - b[i]));
        if (d[i] < b[i]) diff2.push_back(10 - abs(d[i] - b[i]));
        else if (d[i] == b[i]) diff2.push_back(0);
        else diff2.push_back(abs(d[i] - b[i]));
    }
    vector<int> orig1 = diff1, orig2 = diff2;
    for (auto n : diff1) cout << n;
    cout << '\n';
    for (auto n : diff2) cout << n;
    cout << '\n';
    int count = 0;
    int minim1 = INT32_MAX, minim2 = INT32_MAX;
    int maks1 = INT32_MIN, maks2 = INT32_MIN;
    int ans = INT32_MAX;
    int len = 0;
    bool ujung = false;
    while (!ujung)
    {
        minim1 = INT32_MAX;
        minim2 = INT32_MAX;
        for (int i = 0; i < diff1.size(); ++i)
        {
            if (diff1[i] == 0) 
            {
                if (i == diff1.size()-1) 
                {
                    ujung = true;
                    break;
                }
                continue;
            }
            for (int j = i; j < i + 3; ++j)
            {
                if (j == diff1.size()) break;
                if (diff1[j] == 0) break;
                minim1 = min(minim1, diff1[j]);
                minim2 = min(minim2, diff2[j]);
                maks1 = max(maks1, diff1[j]);
                maks2 = max(maks2, diff2[j]);
            }
            for (int j = i; j < i + 3; ++j)
            {
                if (j == diff1.size()) break;
                if (diff1[j] == 0) break;
                if (minim1 <= minim2)
                {
                    diff1[j] -= minim1;
                    diff2[j] = (diff2[j] + minim1) % 10;
                }
                else
                {
                    diff2[j] -= minim2;
                    diff1[j] = (diff1[j] + minim2) % 10;
                }
                //cout << 't' << '\n';
            }
            
            count += min(minim1, minim2);
            //cout << count << '\n';
            cout << i << ' ' << diff1[i] << ' ' << diff2[i] << ' ' << minim1 << ' ' << minim2 << '\n';
            cout << count << '\n';
            break;
        }
    }
    cout << count << '\n';
    ans = count;
    count = 0;
    maks1 = INT32_MIN;
    maks2 = INT32_MIN;
    len = 0;
    ujung = false;
    diff1 = orig1;
    diff2 = orig2;
    while (!ujung)
    {
        minim1 = INT32_MAX;
        minim2 = INT32_MAX;
        for (int i = 0; i < diff1.size(); ++i)
        {
            if (diff1[i] == 0) 
            {
                if (i == diff1.size()-1) 
                {
                    ujung = true;
                    break;
                }
                continue;
            }
            for (int j = i; j < i + 2; ++j)
            {
                if (j == diff1.size()) break;
                if (diff1[j] == 0) break;
                minim1 = min(minim1, diff1[j]);
                minim2 = min(minim2, diff2[j]);
                maks1 = max(maks1, diff1[j]);
                maks2 = max(maks2, diff2[j]);
            }
            for (int j = i; j < i + 2; ++j)
            {
                if (j == diff1.size()) break;
                if (diff1[j] == 0) break;
                if (minim1 <= minim2)
                {
                    diff1[j] -= minim1;
                    diff2[j] = (diff2[j] + minim1) % 10;
                }
                else
                {
                    diff2[j] -= minim2;
                    diff1[j] = (diff1[j] + minim2) % 10;
                }
                //cout << 't' << '\n';
            }
            
            count += min(minim1, minim2);
            //cout << count << '\n';
            cout << i << ' ' << diff1[i] << ' ' << diff2[i] << ' ' << minim1 << ' ' << minim2 << '\n';
            cout << count << '\n';
            break;
        }
    }
    cout << count << '\n';
    ans = min(ans, count);
    //for (auto n : diff) cout << n << ' ';
    cout << ans;
    cout << '\n';
}
/*
390559 772982
482433
628677
0 6 4 2 2
0 8 2 2 2
0 0 0 2 2

260433
840677
2

040433
060677
4

000433
000677
8

000100
000900
11

000000
000000
12

*/
int main() 
{ 
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while (true)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> a1, a2;
        for (int i = 0; i < s1.length(); ++i)
        {
            a1.push_back(s1[i] - '0');
        }
        for (int i = 0; i < s2.length(); ++i)
        {
            a2.push_back(s2[i] - '0');
        }

        solve(a1, a2);
        
        if(cin.eof()) break;
    }
    
    return 0; 
} 

