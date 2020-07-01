#include<bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

class Solution 
{
public:
    int myAtoi(string s) 
    {
        int iNum = 1;
        bool overflow = false;
        unsigned int ans = 0;
        int sign = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (iNum == 1 && (s[i] == ' ' || s[i] == '\"')) continue;
            if (s[i] < '0' || s[i] > '9') 
            {
                if (!(iNum == 1 && (s[i] == '-' || s[i] == '+'))) break;
            }
            if (iNum > 11)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    overflow = true;
                    break;
                }
            }
            else if (iNum == 1)
            {
                if (s[i] == '-')
                {
                    sign = -1;
                    iNum++;
                }
                else if (s[i] == '+' || s[i] == '0')
                {
                    sign = 1;
                    iNum++;
                }
                else if (s[i] >= '1' && s[i] <= '9')
                {
                    sign = 1;
                    ans += s[i] - '0';
                    iNum += 2;
                }
            }
            else if (iNum == 11)
            {
                if (ans == 214748364)
                {
                    if (sign < 0 && (s[i] == '9'))
                    {
                        overflow = true;
                        break;
                    }
                    else if (sign > 0 && (s[i] >= '8' && s[i] <= '9')) 
                    {
                        overflow = true;
                        break;
                    }
                    else if (s[i] >= '0' && s[i] <= '9')
                    {
                        if (ans < 0) ans = ans*10 - (s[i] - '0');
                        else ans = ans*10 + (s[i] - '0');
                        iNum++;
                    }
                }
                else if ((ans > 214748364) && (s[i] >= '0' && s[i] <= '9'))
                {
                    overflow = true;
                    break;
                }
                else if (s[i] >= '0' && s[i] <= '9')
                {
                    if (ans < 0) ans = ans*10 - (s[i] - '0');
                    else ans = ans*10 + (s[i] - '0');
                    iNum++;
                }   
            }
            else
            {
                if (iNum == 2)
                {
                    if (s[i] == '0') continue;
                }
                if (s[i] >= '0' && s[i] <= '9')
                {
                    if (ans < 0) ans = ans*10 - (s[i] - '0');
                    else ans = ans*10 + (s[i] - '0');
                    iNum++;
                }
                else
                {
                    break;
                }
            }
        }
        //cout << ans << endl;
        if (overflow && sign < 0) return -2147483648;
        if (overflow && sign > 0) return 2147483647;
        return ans * sign;
    }
};


int main()
{
    string s;
    getline(cin, s);
    Solution solution;
    cout << solution.myAtoi(s) << endl;
}