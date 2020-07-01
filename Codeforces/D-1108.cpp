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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> kar(3);
    kar[0] = 'R';
    kar[1] = 'G';
    kar[2] = 'B';
    int count = 0;
    if (n >= 3)
    {

        for (int i = 1; i <= n-2; ++i)
        {
            if (s[i-1] == s[i] && s[i] == s[i+1])
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (kar[j] != s[i-1] && kar[j] != s[i+1])
                    {
                        s[i] = kar[j];
                        break;
                    }
                }
                count++;
            }
        }
        for (int i = 1; i <= n-2; ++i)
        {
            if (s[i-1] == s[i] || s[i] == s[i+1])
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (kar[j] != s[i-1] && kar[j] != s[i+1])
                    {
                        s[i] = kar[j];
                        break;
                    }
                }
                count++;
            }
        }
    }
    else
    {
        if (n == 1) 
        {
            count = 0; 
        }
        else 
        {
            if (s[0] == s[1])
            {
                count = 1;
                for (int i = 0; i < 3; ++i)
                {
                    if (kar[i] == s[0])
                    {
                        s[1] = kar[(i+1) % 3];
                        break;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    cout << s << endl;
}