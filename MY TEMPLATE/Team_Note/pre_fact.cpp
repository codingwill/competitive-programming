vector<ll> fac(200500, 0);
 
void preFact()
{
    for (int i = 0; i < inv.size(); ++i)
    {
        fac[i] = fastpow(2, i);
    }
}