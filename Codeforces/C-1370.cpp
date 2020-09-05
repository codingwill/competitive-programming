#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/19
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
        int n;
        cin >> n;
        if ((n % 2 == 1 && n > 1) || n == 2) cout << "Ashishgup" << '\n';
        else if (n == 1) cout << "FastestFinger" << '\n';
        else
        {
            int rangeDiv = n;
            bool canDivided = false;
            for (int i = 3; i * i <= rangeDiv; ++i)
            {
                if (n % i == 0)
                {
                    if (i % 2 == 1 || (n / i) % 2 == 1)
                    {
                        canDivided = true;
                        break;
                    }
                }
            }
            //cout << canDivided << endl;
            if (canDivided && n / 3 != 2) cout << "Ashishgup" << '\n';
            else cout << "FastestFinger" << '\n';
        }
        
    }
}

/*
12 / 3 = 4 - 1 = 3 / 3
A
14 / 7 = 2 - 1 
F
16 - 1 = 15 / 15 
F
18 / 3 = 6 / 3 = 2 - 1
A
20 / 5 = 4 - 1 = 3 / 3
A
22 / 11 = 2 - 1 
F
24 / 3 = 8 - 1 = 7 / 7 
A
28 / 7 = 4 - 1 = 3 / 3
A
30 / 3 = 10 / 5 = 2 - 1
A
32 - 1 = 31 / 31
F



36 / 3 = 12 / 3 = 4 - 1 = 3 / 3 
36 / 9 = 4 - 1 = 3 / 3

1 FastestFinger
2 Ashishgup
3 Ashishgup
4 FastestFinger
5 Ashishgup
6 FastestFinger
7 Ashishgup
8 FastestFinger
9 Ashishgup
10 FastestFinger /5 = 2
11 Ashishgup
12 Ashishgup /3 = 4
13 Ashishgup
14 FastestFinger
15 Ashishgup 
16 FastestFinger
17 Ashisgup
18 Ashisgup /3 = 6 / 3 = 2
19 Ashisgup
20 /5 = 4 - 1 = 3 / 3

FastestFinger
Ashishgup
Ashishgup
FastestFinger
Ashishgup
FastestFinger
Ashishgup
FastestFinger
Ashishgup
FastestFinger
Ashishgup
Ashishgup
Ashishgup
FastestFinger
Ashishgup
FastestFinger
Ashishgup
Ashishgup
Ashishgup
FastestFinger

*/