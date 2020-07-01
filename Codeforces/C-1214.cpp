#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll count = 0;
    bool can = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') count += 1;
        else if (s[i] == ')') count -= 1;
        if (count < -1) can = false;
    }
    if (count != 0) can = false;
    if (can) puts("Yes");
    else puts("No");
}
/*
)())((
-1 0 -1 -2 1 0

((())())
1 2 3 2 1 2 1 0
*/