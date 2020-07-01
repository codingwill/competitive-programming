#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<ll> ans;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> monster;
        ll minim = INT64_MAX;
        ll expl[n];
        ll bullets = 0;
        ll exc = 0;
        for (int i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            monster.push_back(make_pair(a, b));
        }
        
        if (n == 1)
        {
            ans.push_back(monster[0].first);
            continue;
        }
        for (int i = 0; i < n-1; i++)
        {
            expl[i] = (monster[i].second - monster[i+1].first) >= 0 ? 0 : abs(monster[i].second - monster[i+1].first);
        }
        
        expl[n-1] = (monster[n-1].second - monster[0].first) >= 0 ? 0 : abs(monster[n-1].second - monster[0].first);
        if (!expl[n-1] == 0)
        {
            bullets += expl[n-1];
        }
        if (minim > monster[n-1].first)
        {
            exc = expl[n-2];
        }
        minim = min(minim, monster[n-1].first);
        
        for (int i = 0; i < n-1; i++)
        {
            if (!expl[i] == 0)
            {
                bullets += expl[i];
            }
            if (minim > monster[i].first)
            {
                if (i > 0)
                {
                    exc = expl[i-1];
                }
                else
                {
                    exc = expl[n-1];
                }
                
            }
            minim = min(minim, monster[i].first);
        }
        /*
        else if (minim > monster[0].first)
        {
            exc = expl[n-1];
        }
        */
        ll minim2 = INT64_MAX;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                minim2 = min(minim2, monster[i].first + bullets - expl[i-1]);
            else
                minim2 = min(minim2, monster[i].first + bullets - expl[n-1]);
        }
        ans.push_back(minim2);
    }
    for (ll n : ans) cout << n << '\n';
    return 0;
}

/*
1
3
7 15 = 0
2 14 = 0
5 3 = 4

==================

5
7 15 = 2
17 14 = 0
5 3 = 0
2 5 = 1
6 9 = 0

=================
5
10 11 = 6
17 12 = 3
15 8 = 0
4 5 = 1
6 4 = 6

3
1 9 = 1
10 5 = 0
2 8 = 0

3
1 0 = 1
1 0 = 1
1 0 = 1


PATOKAN
1
3
16 24 = 0
11 10 = 28
38 21 = 0
WA 39 -> COR 38

1
3
16 24
11 11
38 21
38

*/
