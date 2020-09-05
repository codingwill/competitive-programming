#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/16
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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

bool sortPairVal(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}

bool sortPairIndex(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll L = 0, R = 0;
        ll ans = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'R' && s[(i+1) % s.length()] == 'L')
            {
                s[i] = '0';
                s[(i+1) % s.length()] = '0';
                //cout << 't' << '\n';
            }
        }
        //cout << s << '\n';
        if (s[s.length()-1] == '0')
        {
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == '0')
                {
                    ans += R/2 + L/2;
                    L = 0;
                    R = 0;
                }      
                else
                {
                    if (s[i] == 'L') L++;
                    else if (s[i] == 'R') R++;
                }
            }
        }
        else
        {
            bool start = false;
            for (int i = 0; i < s.length(); ++i)
            {
                if (start)
                {
                    if (s[i] == 'L') L++;
                    else if (s[i] == 'R') R++;
                }
                if (s[i] == '0') 
                {
                    start = true;
                    ans += R/2 + L/2;
                    L = 0;
                    R = 0;
                }
            }
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == 'L') L++;
                else if (s[i] == 'R') R++;
                if (s[i] == '0') break;
            }
            ans += R/2 + L/2;
        }
        //cout << R << '\n';
        //cout << s << '\n';
        cout << ans << '\n';
    }
}
/*
RLL

1
20
RRRRLLLLLLLLLLLLRRRLRLLRLLL
RRR00LLLLLLLLLLLRR0000L00LL
LRLRLRLRLRLRL

12
LLLLRRLRRRLL
LLLLR00RR00L
RLRLLR

1
12
LLLRRRLRRRLL
LLLRR00RR00L
RLRLRL

RLLR

4
RRRR => 1 AJA
R(L)RR

5
4
RLRL

6
LRRRRR



8
RLLRRRLL
00LRR000
R = 2
L = 1
(MAKS(L, R) / 2) = 2 / 2 = 1

#1: atk 1, atk back, OK
#2: atk 2, atk any, OK
#3: atk 1, NOT atk back, NOT OK
#4: atk 0, atk any, OK
#5: atk 1, NOT atk back, NOT OK
#6: atk 2, atk any, OK
#7: atk 2, atk any, OK
#8: atk 0, atk any, OK

12
LLLLRRLRRRLL
LLLLR00RR00L
LLLLLR + RR
MAKS(5, 1) / 2 + MAKS(2, 0) / 2 = 5/2 + 2/2 = 2 + 1 = 3

5
RRRRR
*/