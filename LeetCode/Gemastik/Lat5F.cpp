#include <iostream>
using namespace std;
using ll = long long int;

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll factorial(ll n){
    ll result = 1;
    for (ll i = 1; i <= n; i++)
    {
        result *= i;
    }
    
    return result;
}

int main(){
    ll m, n;
    cin >> m >> n;

    ll factorial(min(m, n)) << '\n';
}