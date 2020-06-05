#include <bits/stdc++.h>

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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n_zero = 0, n_one = 0;
        bool beautiful = true;
        string a = "101", b = "010";
        int ai = 0, bi = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0') ++n_zero;
            else ++n_one;
            if (s[i] == a[ai]) ++ai;
            if (s[i] == b[bi]) ++bi;
            if (ai >= 2 || bi >= 2) beautiful = false; 
        }
        if (beautiful) cout << '0' << '\n';
        else
        {
            int zero[s.length()], one[s.length()];
            zero[0] = 0;
            one[0] = 0;
            int ans = INT32_MAX;
            //count zero from left
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == '0')
                {
                    if (i == 0) zero[i] = 1;
                    else
                    {
                        zero[i] = zero[i-1] + 1;
                    }
                }
                else
                {
                    if (i == 0) continue;
                    else
                    {
                        zero[i] = zero[i-1];
                    }
                }
            }
            //count one from left
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == '1')
                {
                    if (i == 0) one[i] = 1;
                    else
                    {
                        one[i] = one[i-1] + 1;
                    }
                }
                else
                {
                    if (i == 0) continue;
                    else
                    {
                        one[i] = one[i-1];
                    }
                }
            }
            /*
            for (int i = 0; i < s.length(); ++i)
            {
                cout << one[i] << ' ';
            }
            cout << endl;
            */
            for (int i = 0; i < s.length(); ++i)
            {
                //one left zero right
                int count = zero[i] + (one[s.length()-1] - one[i]);
                ans = min(ans, count);
                //one right zero left
                count = one[i] + (zero[s.length()-1] - zero[i]);
                ans = min(ans, count);
            }

            cout << ans << '\n';
        }
    }
}
/*

01111110001010101

0 1 0 1 0 1 0 1 0 1
1 6 3 1 1 1 1 1 1 1


1
0110000

1
10110000

0 1 0
1 2 4

1 0 1 0
1 1 2 4

00001100000111111111100111
0 1 0 1  0 1
4 2 5 10 2 3
*/