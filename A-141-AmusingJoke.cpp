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
    string s1, s2, target, combined;
    cin >> s1 >> s2 >> target;
    combined = s1 + s2;
    sort(combined.begin(), combined.end());
    sort(target.begin(), target.end());
    if (combined == target) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}