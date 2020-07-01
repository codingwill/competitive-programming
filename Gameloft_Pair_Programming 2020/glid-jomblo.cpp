#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;

int dp[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        dp[s[i] - 'A']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (dp[s[i] - 'A'] == 1)
        {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << "HORE!" << endl;
} 
