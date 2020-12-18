vector<ll> inv(200500, 0);
const int MOD = 1e9 + 7;

void preInv()
{
    for (int i = 0; i < inv.size(); ++i)
    {
        inv[i] = fastpow(fastpow(2, i), MOD-2);
    }
}