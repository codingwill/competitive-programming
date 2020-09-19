#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y, ll n);
ll multisetc(ll n, ll k);
void solve();

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
	
	return 0;
}

void solve(){
	int n;
	cin >> n;
	vector <int> a;
	int sum = 0;
	int temp;
	while(cin >> temp){
		a.push_back(temp);
		sum += temp;
	}
	n -= sum;
	cout << multisetc(n+a.size()-1, n) << "\n";
}

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

ll multisetc(ll n, ll k){
	ll ans = 1;
	for(int i = n; i >= max(k, n-k); i--)
		ans = ((ans%MOD) * (i%MOD))%MOD;
	for(int i = 2; i <= min(k, n-k); i++)
		ans /= i;
	return ans;
}