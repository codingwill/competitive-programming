#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/18
*/
using namespace std;
using ll = long long int;

string ans = "codeforce", s = "s";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k;
    cin >> k;
        int j = 1;
        for (; j <= k; j += j)
        {
            if (j > pow(2, 26)) break;
            if (j >= 2) s += s;
        }
        j /= 2;
        printf("codeforce");
        for (int i = 0; i < k / j; ++i)
        {
            printf("%s", s.c_str());
        }
        for (int i = 0; i < k % j; ++i)
        {
            printf("s");
        }
    
    return 0;
}