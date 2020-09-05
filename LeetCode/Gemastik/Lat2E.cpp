#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/16
*/
using namespace std;
using ll = long long int;

void solve();
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
	
	return 0;
}

ll myPow(ll x, ll y, ll n = BIG) {
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

void solve()
{
	int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll ans = (m * (m - 1)) % MOD;
        if (n == 1)
        {
            cout << m << '\n';
        }
        else if (n == 2)
        {
            cout << ans << '\n';
        }
        else
        {
            ans %= MOD;
            ans = ans * myPow(m - 2, n - 2, MOD);
            cout << (ans % MOD) << '\n';
        }
    }
}
/*
2 2
2

2 3
6

3 2 //misal {A, B}
A A A // P
A A B
A B A // P
B A A 
A B B
B A B // P
B B A
B B B // P
// 8 - 4
(M) (M-1) = 2 * 1 = 2 //HARUSNYA 4
BERARTI MESTINYA (M) * M(-1) * SESUATU?
M (M-1) (X) = 2 * 1 * X = 4
X = 4/2
X = 2
X := M?
//eh M ga boleh kurang dari N ding, soalnya kan SET


3 3 //misal (A, B, C)
PALINDROM
A A A
B B B
C C C
A B A
A C A
B A B
B C B
C A C
C B C

NONPALINDROM
A B C
B A C
B C A

3 3 (PAKE KOMBINATORIAL KOTAK)
1 | 2 | 3
3 | 2 | 1

4 3 
1 | 2 | 3 | 4
4 | 3 | 2 | 2 <<


*/