#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std
//AUTHOR'S NAME
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
        long double h, c, tar;
        cin >> h >> c >> tar;
        long double prev = 0;
        ll count = 1;
        long double amount = h;
        long double target = tar;
        long double minim = 1e10;
        ll ans = 1;
        for (int i = 0; i < 10005; ++i)
        {
            if (abs(target - amount) < 1e-6)
            {
                break;
            }
            
            if (count % 2 == 1)
            {
                amount += c;
            }
            else if (count % 2 == 0)
            {
                amount += h;
            }
            
            prev = amount;
            target += tar;
            //cout << 't' << endl;
            ++count;
            if (count != 1)
            {
                if (minim > abs(amount/count - tar))
                {
                    minim = abs(amount/count - tar);
                    ans = count;
                }
            }
        }
        /*
        41 15
        41 56 97 112 153 168 209 224 265 280 321 336
        2 2.33333
        2.33333 2
        2 0.6
        0.6 2
        2 0.142857
        0.142857 1.25
        1.25 0.555556
        0.555556 0.6
        0.6 0.818182
        0.818182 0.166667


        41-30 56-60
        56-60 97-90
        3
        30 10 20
        41 15 30
        18 13 18
        */
        cout << ans << '\n';
    }
}