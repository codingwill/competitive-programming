#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0;
        if (s.length() <= 2)
        {
            cout << s << '\n';
            continue;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0') cnt0++;
            else cnt1++;
        }
        if (cnt0 == 0 || cnt1 == 0)
        {
            cout << s << '\n';
            continue;
        }
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i] == s[i+1])
            {
                s.insert(i+1, s[i] == '0' ? "1" : "0");
            }
        }    
        cout << s << endl;
    }
}

/*
t=001101
s=010101010
s=101010101

t=000001
s=0101010101

t=000000
s=101010101010
t=000011
s=
*/