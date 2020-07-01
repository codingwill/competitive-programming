#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/18
*/
using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a, w;
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ll input;
            cin >> input;
            a.push_back(input);
        }
        sort(a.begin(), a.end(), greater<int>());

        for(int i = 0; i < k; ++i)
        {
            ll input;
            cin >> input;
            w.push_back(input);
        }
        sort(w.begin(), w.end());

        //highest happiness assigned to each friend first
        for (int i = 0; i < w.size(); ++i)
        {
            ans += a[i];
            if (w[i] == 1) ans += a[i];
        }
        //cout << ans << endl;
        //the rest assigned to the rest of friends, but prioritize friend with lower W
        //so the lowest happiness will be maxed
        int j = 0; //pointer of W
        for (int i = w.size(); i < a.size(); ++i)
        {
            if (w[j] == 1) 
            {
                ++j;
                --i;
                continue;
            }
            //cout << 't' << '\n';
            ans += a[i + (w[j] - 2)];
            i += w[j] - 2;
            ++j;
        }
        
        cout << ans << '\n';
    }
}

/*
1
8 4
4 -8 45 26 37 14 -7 -52
2 1 3 2
104

45 + 37 + 26 + 14  = 122
     4    -7   -8
               -52
45   4    -7   -52 = 112               
*/