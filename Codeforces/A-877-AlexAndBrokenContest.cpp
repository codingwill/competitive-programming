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
    string s;
    string name[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    cin >> s;
    int count = 0;
    int found;
    for (int i = 0; i < 5; i++)
    {
        found = s.find(name[i]);
        if (found != string::npos) count++;
        found = s.find(name[i], found+1);
        if (found != string::npos) count++;
    }
    if (count == 1) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}