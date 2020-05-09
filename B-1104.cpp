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
    string s;
    cin >> s;
    stack<char> p;
    int ans = 0;
    p.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        if (!p.empty())
        {
            if (p.top() == s[i])
            {
                ans++;
                p.pop();
            }
            else p.push(s[i]);
        }
        else p.push(s[i]);
    }
    if (ans % 2 == 1) puts("Yes");
    else puts("No");
    //cout << ans << endl;
}

/*
dabbacded
*/