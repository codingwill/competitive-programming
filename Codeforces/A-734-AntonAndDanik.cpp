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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countA = 0, countD = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D') countD++;
        else countA++;
    }
    if (countD > countA) cout << "Danik\n";
    else if (countD == countA) cout << "Friendship\n";
    else if (countD < countA) cout << "Anton\n";
    return 0;
}