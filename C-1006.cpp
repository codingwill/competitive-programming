#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n-1;
    ll countL = 0, countR = 0;
    ll ans = -1;
    while (l <= r)
    {
        if (countL > countR)
        {
            countR += a[r];
            r--;
        }
        else if (countL < countR)
        {
            countL += a[l];
            l++;
        }
        else
        {
            ans = max(ans, countL);
            countL += a[l];
            l++;
            //cout << 't';
        }
    }
    if (countL == countR) ans = max(ans, countL);
    cout << ans << '\n';
}