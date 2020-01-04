#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool highFirst(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int minim = INT32_MAX;
    for (char i = 'A'; (int)i < (int)'A' + k ; i++)
    {
        int count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (i == s[j]) count++;
        }
        minim = min(minim, count);
    }
    cout << minim * k << '\n';
    return 0;
}
