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

void solve(){
	int n,a[1002],b[1002];
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	
	int cb = 0;
	while(cb < n-2){
		if(b[cb+1] >= b[cb+2]){
			b[cb+1] = 0;
			cb += 2;
		} else {
			cb += 1;
		}
	}
	
	int ta[1002],tb[1002];
	
	tb[0] = b[0];
	for(int i=1;i<n;i++){
		tb[i] = tb[i-1] + b[i];
	}
	
	ta[0] = a[0] + tb[0];
	for(int i=1;i<n;i++){
		if(ta[i-1] >= tb[i]){
			ta[i] = ta[i-1] + a[i];
		} else {
			ta[i] = tb[i] + a[i];
		}
	}
	
	cout << ta[n-1] << "\n";
	
}


