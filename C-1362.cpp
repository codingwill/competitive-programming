#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/04
*/
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<ll> pat(65);
    long long beg = 2;
    for (int i = 1; i <= 64; ++i)
    {
        pat[i] = beg;
        beg *= 2;
    }
    while (t--)
    {
        long long n;
        long long start = 2;
        cin >> n;
        long long count = 2;
        long long ans = 0;
        ans += (n+1)/2; 
        while (start <= n)
        {
            ans += count * ((n + start)/pat[count]);
            ++count;
            start *= 2;
        }
        cout << ans << '\n';
    }
}

/*
2000000000000
3921875000000
3999999999987
1 dif 2
2 dif 4
3 dif 8
4 dif 16
5 dif 32

00000 = 0
00001 = 1
00010 = 2 (2)
00011 = 1
00100 = 3 (4)
00101 = 1
00110 = 2 
00111 = 1
01000 = 4 (8)
01001 = 1
01010 = 2
01011 = 1
01100 = 3
01101 = 1
01110 = 2
01111 = 1
10000 = 5 (16)
10001 = 1
10010 = 2
10011 = 1
10100 = 3
10101 = 1
10110 = 2
10111 = 1
11000 = 4
11001 = 1
11010 = 2
11011 = 1
11100 = 3
11101 = 1
11110 = 2
 11111 = 1
100000 = 6 (32)
100001 = 1
100010 = 2
100011 = 1
100100 = 3
100101 = 1
100110 = 2
100111 = 1
101000 = 4
101001 = 1
101010 = 2
101011 = 1
101100 = 3
101101 = 1
101110 = 2
101111 = 1
110000 = 5
*/