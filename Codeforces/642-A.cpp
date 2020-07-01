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
        string a;
        cin >> a;
        ll k;
        cin >> k;
        for (int i = 0; i < k-1; i++)
        {
            ll minim = 10, maks = -1;
            for (int j = 0; j < a.length(); j++)
            {
                minim = min(minim, (ll)(a[j] - '0'));
                maks = max(maks, (ll)(a[j] - '0'));
            }
            a = to_string(stoll(a) + (minim*maks));
            if (minim == 0)
            {
                break;
            }
        }
        cout << a << '\n';
    }
}