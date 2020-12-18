using ll = long long int;
const int MOD = 1e9 + 7;

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