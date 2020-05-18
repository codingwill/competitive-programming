#include<bits/stdc++.h>
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n+1);
    vector<ll> dp(205000, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll tele = 1;
    vector<pair<ll, ll>> teleMark(n+1, make_pair(0, 0));
    map<ll, ll> visit;
    ll cycle = 0;
    ll startCycle = 0;
    for (int i = 1; i <= n; i++)
    {
        visit[tele]++;
        if (visit[tele] == 1) 
        {
            teleMark[tele].first = i;
        }
        else if (visit[tele] == 2) 
        {
            teleMark[tele].second = i;
            cycle = tele;
            break;
        }
        tele = a[tele];
    }
    ll dpRange = teleMark[cycle].second - teleMark[cycle].first;
    startCycle = teleMark[cycle].first;
    for (int i = 1; i <= dpRange; i++)
    {
        dp[i] = a[cycle];
        cycle = a[cycle];
    }
    cout << dp[(((k-startCycle) % (dpRange)) + 1)] << '\n';
}