#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
int ans[5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 5; i++)
    {
        string s;
        getline(cin, s);
        int count = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (((int)s[j] >= 65 && (int)s[j] <= 90) || ((int)s[j] >= 97 && (int)s[j] <= 122))
            {
                count++;
            }
            else
            {
                if (count >= 4)
                {
                    ans[i]++;
                }
                count = 0;
            }
        }
        if (count >= 4) ans[i]++;
    }
    for (int n : ans) cout << n << '\n';
    return 0;
}