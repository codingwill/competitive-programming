#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int upCount = 0, lowCount = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] <= (int)'Z')
        {
            upCount++;
        }
        else
        {
            lowCount++;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (upCount <= lowCount)
        {
            if (s[i] <= (int)'Z')
            {
                s[i] = (int)s[i] + (int)'a' - (int)'A';
            }
        }
        else
        {
            if (s[i] > (int)'Z')
            {
                s[i] = (int)s[i] - (int)'a' + (int)'A';
            }
        }
    }
    cout << s << '\n';
    return 0;

}
