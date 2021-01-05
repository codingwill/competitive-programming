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
    vector<int> satu;
    int last = 0;
    for (int i = 0; i < n-1; ++i)
    {
        cin >> last;
        if (last == 1)
        {
            satu.push_back(i);
        }
    }
    int maxLen = -1;
    if (satu.size() == 0)
    {
    	cout << n-1 << '\n';
        return;
	}
    for (int i = 1; i < satu.size(); ++i)
    {
        maxLen = max(maxLen, satu[i] - satu[i-1]);
    }
    if (last == 0)
    {
        cout << (n-2) - satu[satu.size()-1] + 1 << '\n';
    }
    else
    {
        if (maxLen > 1)
        {
//            if (n <= 4) cout << 1 << '\n';
//            else 
			cout << 2 << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }
    


}
