#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll x;
        cin >> n >> x;
        ll count = 0, power = 1, kills = 0;
        for (ll i = 0; i < n;)
        {
            //cout << power << endl;
            i += power;
            kills += power;
            if (kills >= x)
            {
                power = power * 2;
                kills = kills % x;
            }
            count += 1;
        }
        cout << count << '\n';
    }
}