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
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 || y1 == y2)
        {
            cout << 1 << '\n';
            continue;
        }
        cout << (x2-x1) * (y2-y1) + 1 << '\n';
    }
}
/*
1 1 3 3
28 29 30 30 31 32
6-1 = 5

1 1 2 4
26 27 28 29

1 1 4 4
[69] 70 71 72 71 72 73 73 74 75 72 73 74 74 75 76 75 76 77 [78]
69 70 71 72 73 74 75 76 77 78


E(x2,y1)~(x2,y2) + E(x1, y1)~(x2, y1)] - [E(x1,y1)~(x1, y2) + E(x1, y2)~(x2, y2)]
E(SUM) dicari pake rumus deret aritmatika level 2
deret level 1: beda = 1, a kolom = index y, a baris = (index x)+1, suku akhir = 
Sn = (1/3) n^3 + n^2 - (1/3) n
  1  1  1
 3 4  5  6
4 7 11 16 22
3
18
60

 1  2  4  7 11 16 22
 3  5  8 12 17 23
 6  9 13 18 24
10 14 19 25
15 20 26
21 27
28
*/