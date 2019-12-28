#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

using ll = long long int;
vector<ll> s, sCopy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll minim = INT64_MAX;
        int minimIndex;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll input;
            cin >> input;
            if (minim > input)
            {
                minim = input;
                minimIndex = i;
            }
            s.push_back(input);
        }
        sCopy.assign(s.begin(), s.begin()+minimIndex);
        for (int i = 0; i < sCopy.size(); i++)
        {
            ans += sCopy[i];
        }
        ans += (s.size()-minimIndex) * minim;
        cout << ans << '\n';
        s.clear();
    }
    return 0;
}