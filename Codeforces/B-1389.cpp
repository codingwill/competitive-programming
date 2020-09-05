#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, z;
        cin >> n >> k >> z;
        vector<ll> a(n), sum(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (i > 0)
                sum[i] += sum[i-1] + a[i];
            else
                sum[i] = a[i];
        }
        ll maxPair = -1;
        pair<ll, ll> pMax, iMax;
        ll ans = 0;
        for (int i = 1; i < k + 1; ++i)
        {
            if (a[i] + a[i-1] > maxPair)
            {
                pMax = make_pair(a[i-1], a[i]);
                iMax = make_pair(i-1, i);
            }
            maxPair = max(maxPair, a[i] + a[i-1]);
        }        
        ans += sum[iMax.second];
        ans += (min(k - iMax.second, z*2) / 2) * pMax.second;
        ans += (min(k - iMax.second, z*2) + 1) / 2 * pMax.first;
        if (z == 0)
            ans = sum[k];
        cout << ans << '\n';
        
    }
}

/*
256
625
562

50505
05055
55050

010101
101010
101010


*/