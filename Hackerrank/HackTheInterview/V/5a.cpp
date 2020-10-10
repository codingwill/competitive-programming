#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); i++)
long mod = (long) 1e9 + 7;
 
int main(){
    
    long n, p, rem = 0, pp = 1, ans = 0;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<long> v(p,0);
    v[0]++;
    
    if(p == 2){
        for(int x = n; x > 0; x--){
            if((s[x - 1] - '0') % 2 == 0) ans += x;
        }
        cout << ans << "\n";
        return 0;
    }
 
    if(p == 5){
        for(int x = n; x > 0; x--){
            if((s[x - 1] - '0') % 5 == 0) ans += x;
        }
        cout << ans << "\n";
        return 0;
    }
 
    rep(i,n){
        rem = (rem + (s[n - 1 - i] - '0') * pp) % p;
        v[rem]++;
        pp = pp * 10 % p;
    }
    
    rep(i,p) if(v[i] > 0) ans += v[i] * (v[i] - 1) / 2;
    
    cout << ans << "\n";
    
    return 0;
}