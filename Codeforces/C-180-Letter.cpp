#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> lower(s.length(), 0), upper(s.length(), 0);
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] - 'a' >= 0) 
            if (i > 0) lower[i] += lower[i-1] + 1;
            else lower[i] = 1;
    }
    for (int i = s.length()-1; i >= 0; --i)
    {
        if (s[i] - 'a' < 0) 
            if (i < s.length()-1) upper[i] += upper[i+1] + 1;
            else upper[i] = 1;
    }
    int ans = INT32_MAX - 10;
    for (int i = 0; i < s.length(); ++i)
    {
        if ()
    }
    cout << ans << '\n';
}