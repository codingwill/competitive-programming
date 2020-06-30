#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.length() <= 1) return s;
        string ans = "";
        pair<int, int> pointerAns;
        int maxLength = -1;
        //ganjil
        if (s.length() >= 3)
        {
            for (int i = 1; i < s.length()-1; ++i)
            {
                int l = i-1;
                int r = i+1;
                while (l >= 0 && r < s.length())
                {
                    if (s[l] != s[r]) break;
                    if (r-l+1 > maxLength)
                    { 
                        maxLength = r-l+1;
                        pointerAns = make_pair(l, r);
                    }
                    ++r;
                    --l;
                }
            }

        }
        
        //genap
        for (int i = 0; i < s.length()-1; ++i)
        {
            int l = i;
            int r = i+1;
            while (l >= 0 && r < s.length())
            {
                if (s[l] != s[r]) break;
                
                if (r-l+1 > maxLength)
                { 
                    maxLength = r-l+1;
                    pointerAns = make_pair(l, r);
                    cout << pointerAns.first << ' ' << pointerAns.second << '\n';
                }
                ++r;
                --l;
            }
        }
        
        //jawaban
        return s.substr(pointerAns.first, pointerAns.second - pointerAns.first + 1);
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("bb") << '\n';
}