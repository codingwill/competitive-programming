#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const ll BIG = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

void solve();

ll fastpow(ll x, ll y, ll n = MOD)
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

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int maks = 0;
    int input;
    bool isSatu = true;
    if (n == 2) 
    {
        cin >> input;
        cout << 1 << '\n';
        return;
    }
    else if (n == 3)
    {
        cin >> input >> input;
        if (input == 1)
        {
            cout << 1 << '\n';
        }
        else cout << 2 << '\n';
    }
    else
    {
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> input;
            if (input == 0)
            {
                if (i != 0) isSatu = false;
                maks = maks + 1;
            }
            else
            {
                maks = 1;
            }
        }
        if (isSatu) cout << 1 << '\n';
        else if (input == 1) cout << 2 << '\n';
        else cout << maks << '\n';
    }
}
