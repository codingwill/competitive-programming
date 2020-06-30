#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/23
*/
using namespace std;
using ll = long long int;

void cleanString(string &s, int n)
{
    int zero = 0, one = n-1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            one = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            zero = i;
            break;
        }
    }
    if (one < zero)
    {
        s.erase(s.begin() + one, s.begin() + zero);
    }
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
        string s;
        cin >> s;
        cleanString(s, n);
        cout << s;
        cout << '\n';
    }
    return 0;
}
/*
1100101001


10110
1010
100
10
0
*/

/*
while (p2 < n)
        {
            if (s[p1] == '1' && s[p2] == '0')
            {
                
                if (p1 > 0 && p2 < n-1)
                {
                    //11001101 -> 1-001101
                    if (s[p1 - 1] == '1' && s[p2 + 1] == '0')
                    {
                        s[p2] = '-';
                        ++p2;
                    }
                    else if (s[p1 - 1] == '1' && s[p2 + 1] == '1')
                    {
                        //---01101 -> ---01-01
                        s[p1] = '-';
                        --p1;
                    }
                    else if (s[p1 - 1] == '0' && s[p2 + 1] == '0')
                    {
                        s[p2] = '-';
                        ++p2;
                    }
                    else
                    {
                        s[p1] = '-';
                        --p1;
                    }
                    
                }
                else if (p1 == 0 && p2 == n-1)
                {
                    if (s[p1] == '1' && s[p2] == '0')
                    {
                        s[p1] = '-';
                        ++p2;
                    }
                } 
                else if (p1 == 0)
                {
                    //1-001101 -> 1--01101 -> ---01101
                    if (s[p1] == '1' && s[p2] == '0')
                    {
                        if (s[p2 + 1] == '0')
                        {
                            s[p2] = '-';
                            ++p2;
                        }
                        else //101 - > -01
                        {
                            s[p1] = '-';
                            p1 = p2;
                            ++p2;
                        }
                    }
                }
                else if (p2 == n-1)
                {
                    if (s[p1] == '1' && s[p2] == '0')
                    {
                        s[p1] = '-';
                        --p1;
                    }
                }
                
            }
            else
            {
                ++p1;
                ++p2;
            }
        }
*/

/*
for (int i = 1; i < n-1; ++i)
        {
            if (s[i] == '0')
            {
                //left = 1 & right = 0
                if(s[p1] == '1' && s[p2] == '0')
                {
                    //1001 -> 1-01 -> --01
                    s[i] = '-';
                    ++p2;
                }
                else if (s[p1] == '1' && s[p2] == '1')
                {
                    //1011 -> -011 ->
                    s[p1] = '-';
                    if (p1 > 0)
                    {
                        --p1;
                        ++p2;
                    }
                    else
                    {
                        p1 = i;
                        ++p2;
                    }
                }
            }
            else
            {
                ++p1;
                ++p2;
            }
        }
        for (char a : s) 
        {
            if (a != '-') cout << a;
        }
        cout << '\n';
    }
*/