#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

bool same[205*205];
ll dp[205*205];

ll mod(ll a, ll b)
{
    if (a % b == 0) return b;
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
        int a, b, q;
        cin >> a >> b >> q;
        dp[0] = 0;
        ll patternCount = 0;
        for (int i = 1; i <= a*b; i++)
        {   
            dp[i] = dp[i-1];
        
            if ((i % a) % b != (i % b) % a) 
            {
                same[i] = true;
                dp[i]++;
                patternCount++;
            }
            else same[i] = false;
        }
        for (int z = 0; z < q; z++)
        {
            ll l, r;
            cin >> l >> r;
            ll count = 0;
            ll cycle = a * b;
            // 3 state -> [***|] [***|***] [***|...|***] * => index != a x b, | => index == a x b, ... => multiple of |***|

            ll mostLeft = l + (cycle - mod(l, cycle));
            ll mostRight = r - (r % cycle);
            ll blocks = (mostRight-mostLeft)/cycle;
            if (blocks >= 1) // [***|...|***] or [|***|]
            {
                count += dp[cycle] - dp[mod(l, cycle) - 1]; //leftest block
                count += blocks * dp[cycle];
                count += dp[r % cycle];
            }
            else if (l < mostLeft && r <= mostLeft) // ***| or ***
            {
                count += dp[mod(r, cycle)] - dp[mod(l, cycle) - 1];
            }
            else if (l <= mostLeft && r > mostLeft) // ***|*** or |***
            {
                count += dp[cycle] - dp[mod(l, cycle) - 1];
                count += dp[r % cycle];
            }
            cout << count;
            if (z < q-1) cout << ' ';
        }
        cout << '\n';
    }
}
/*
25569 265987
4 9
180317

1
45 55 1
1 5869
3010

1
45 55 1
1 2555
26

1. bilangan yang habis dibagi a x b sudah pasti sama (bukan set).
antara 100-200, yang hbs dbg 56 yaitu {102, 158} = 2.

2. Cari bilangan yang ketika dibagi nilai max(a, b) itu bersisa min(a, b)
contoh kasus a = 7, b = 8: y
*/

/*
7 mod 7 = 0 mod 8 = 0
7 mod 8 = 1 mod 8 = 1

8 mod 7 = 1 mod 8 = 1
8 mod 8 = 0 mod 7 = 0

9 mod 7 = 2 mod 8 = 2
9 mod 8 = 1 mod 7 = 1

*/

/*
8 mod 6 = 2 mod 4 = 2
8 mod 4 = 0 mod 6 = 0

9 mod 6 = 3 mod 4 = 1
9 mod 4 = 1 mod 6 = 1

10 mod 6 = 4 mod 4 = 0
10 mod 4 = 2 mod 6 = 2

11 mod 6 = 5 mod 4 = 1
11 mod 4 = 3 mod 6 = 3

12 mod 6 = 0 mod 4 = 0
12 mod 4 = 0 mod 6 = 0

13 mod 6 = 1 mod 4 = 1
13 mod 4 = 1 mod 6 = 1

14 mod 6 = 2 mod 4 = 2
14 mod 4 = 2 mod 6 = 2

15 mod 6 = 3 mod 4 = 3
15 mod 4 = 3 mod 6 = 3

16 mod 6 = 4 mod 4 = 0
16 mod 4 = 0 mod 6 = 0

17 mod 6 = 5 mod 4 = 1


18 mod 6 = 0 mod 4 = 0
18 mod 4 = 2 mod 6 = 2
*/