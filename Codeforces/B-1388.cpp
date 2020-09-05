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
    while (t--)
    {
        int n;
        cin >> n;
        deque<char> s;
        for (int i = 0; i < n; ++i)
        {
            if (i % 4 == 0 ) s.push_back('8');
            else s.push_front('9');
        }
        while (!s.empty())
        {
            cout << s.front();
            s.pop_front();
        } 
        cout << '\n';
    }
}

/*
9998
1001100110011000
99988
10011001100110001000
999988
100110011001100110001000
*/
