#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int num = t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<ll> a(k), dp(k, 0);
        for (int i = 0; i < k; ++i)
        {
            cin >> a[i];
        }
        ll minim = 100000002, maks = -100000003;
        ll cur = 0, count = 0, dist = 0;
        //cout << 0 << ' ';
        for (int i = 1; i < k; ++i)
        {
            if (a[i] > a[i-1])
            {
                ++cur;
            }
            else if (a[i] < a[i-1])
            {
                --cur;
            }
            dp[i] = cur;
            //cout << cur << ' ';   
        }
        for (int i = 0; i < k-4; ++i)
        {
            bool asc = true, desc = true;
            //menaik
            for (int j = i+1; j < i+5; ++j)
            {
                if (a[j] <= a[j-1]) asc = false;
            }
            for (int j = i+1; j < i+5; ++j)
            {
                if (a[j] >= a[j-1]) desc = false;
            }
            if (desc || asc)
            {
                ++count;
                i += 3;
            }
        }
        cout << "Case #" << num-t << ": " << count << '\n';
    }
}

/*
12
1 2 3 4 5 6 5 4 5 6 7 8
A B C D A D B A 

9 8 7 6 5 4 3 2 1
D C B A D C B A D
B A D C B A D B C

3 6 5  1 9  7  3  9  8  6
0 1 0 -1 0 -1 -2 -1 -2 -3
= + -  - +  -  -  +  -  - 
B C B  A C  B  A  C  B  C

1
9
1 2 3 4 5 6 7 8 9
A B C D A B C D A

1 2 3 4 3 3 3 1 0 2 3 7
  + + + - = = - - + + +
0 1 2 3 0 0 0 -1 -2 1 0 1
*/