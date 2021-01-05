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

int a[100002] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void solve()
{
    int n,last=0,c1=0;;
    
    cin >> n;
    
    for(int i=1;i<n;i++){
    	cin >> a[i];
    	if(a[i] == 1){
    		if(i > last){
    			last = i;
			}
    		c1++;
		}
	}
	
	if(n == 2){
		cout << "1\n";
	} else if(n == 3){
		if(last == n-1){
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	} else if(c1 == n-1){
		cout << "1\n";
	} else if(last == n-1){
		cout << "2\n";
	} else {
		cout << n-last << "\n";
	}
    
    
    
    
    
    
    
    
    
    
    
    
    


}
