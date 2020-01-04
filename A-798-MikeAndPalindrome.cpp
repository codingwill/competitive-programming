#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string sCopy;
    stack<char> kon;
    int count = 0;
    for (int j = 0; j < s.length()/2; j++)
    {
        kon.push(s[j]);
    }
    for (int j = s.length()/2; j < s.length(); j++)
    {
        if (s.length() % 2 == 1 && s.length()/2 == j) continue;
        if (kon.top() != s[j]) count++;
        kon.pop();
    }
    if (count == 1)
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;

}