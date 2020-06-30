#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/28
*/
 
using namespace std;
using ll = long long int;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a;
        set<ll> unique;
        bool divisible = true;
        for (ll i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            unique.insert(input);
            if (input % k != 0) divisible = false;
            a.push_back(input);
        }
        if (divisible)
        {
            cout << 0 << '\n';
            continue;
        }
        //cari modus
        map<ll, ll> countMode;
        set<ll> incrUsed;
        ll most = 0; //mode
        ll minim = INT64_MAX; //minim element
        ll ans = 0;
        for (ll i = 0; i < n; ++i)
        {
            while (true)
            {
                if (a[i] % k == 0) break; //GARA GARA KURANG INI JADI WA :(
                if (countMode[a[i]] * k >= a[i] && incrUsed.find((countMode[a[i]] * k) - a[i] + 1) == incrUsed.end()) break;
                ++countMode[a[i]];
                //cout << a[i] << ' ' << countMode[a[i]] * k << endl;
            }
            incrUsed.insert((countMode[a[i]] * k) - a[i] + 1);
            ans = max(ans, (countMode[a[i]] * k) - a[i] + 1);
            most = max(most, countMode[a[i]]);
            minim = min(minim, a[i]);
        }
 
        cout << ans << '\n';
        //cout << endl;
        /*
        1
        6 9
        2 7 15 19 16 25
        7 2 4  8  11 20
        2 7 6  1  7  7
        2 7 6  1  7  7  
 
        21 (output)
        11 (expected)
 
        1
        4 4
        2 1 3 3
        2 3 1 5 (5)
 
        3 3 2 1
        1 5 2 3 (6)
        
        1 2 3 3
        3 2 1 5
 
        10 6
        8 7 1  8 3 7  5 10 8  9
        8 5 11 4 3 17 1 2  16 15
        */
        //cout << (k * most) - (minim - 1) << '\n';
        
        //destroyer
        a.clear();
        unique.clear();
    }
}
 
/*
1
4 2
5 6 2 2
6 8 2 4
1 2 0 2
 
1
6 9
5 9 12 11 5 4
4 0 
15
 
10 6
8 7 1 8 3 7 5 10 8 9
8 5 11 4
 
1 1 2 3
 
 */