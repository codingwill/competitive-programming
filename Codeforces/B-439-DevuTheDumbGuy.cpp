#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define ll long long
#define ulli unsigned long long int
using namespace std;

int main()
{
    ulli n, x;
    cin >> n >> x;
    ulli chapter[n];
    rep(i, n)
    {
        cin >> chapter[i];
    }
    sort(chapter, chapter+n);
    ulli ans = 0;
    rep(i, n)
    {
        ans += chapter[i] * x;
        if (x > 1) 
            x -= 1;
    }
    cout << ans << "\n";
    return 0;
}