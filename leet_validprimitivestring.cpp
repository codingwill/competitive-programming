#include <bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    string answer = "";
    stack<int> parentheses;
public:
    
    string removeOuterParentheses(string S) 
    {
        for (int i = 0; i < S.length(); ++i)
        {
            if (S[i] == '(')
            {
                parentheses.push(S[i]);
                if (parentheses.size() > 1) answer += S[i];
            }
            else
            { 
                if (parentheses.size() > 1) answer += S[i];
                parentheses.pop();
            }
        }
        return answer;
    }
};
