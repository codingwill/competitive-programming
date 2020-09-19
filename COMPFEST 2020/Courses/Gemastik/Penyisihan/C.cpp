#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;
 
ll fastpow(ll x, ll y, ll n);
void solve();
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
	solve();
 
	return 0;
}
 
void solve(){
	int t;
	cin >> t;
	while(t--){
		int p, q, m;
		cin >> p >> q >> m;
		if(log2(p)+log2(q) < m)
			p = q = 0;
		while(m-- && (p > 0 || q > 0)){
			if(p > q)
				p /= 2;
			else
				q /= 2;
		}
		(p > q)? cout << p << " " << q: cout << q << " " << p;
		cout << endl;
	}
}
 
ll fastpow(ll x, ll y, ll n = BIG){
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