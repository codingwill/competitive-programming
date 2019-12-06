#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i+1])
        {
            total++;
        }
    }
    cout << total << endl;
}