#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<string> commonChars(vector<string>& A) 
    {
        vector<map<char, int>> countChar(A.size());
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < A[i].length(); ++j)
            {
                countChar[i][A[i][j]]++;
            }
        }
        //cout << countChar[0]['l'] << endl;
        vector<string> ans;
        for (int i = (int)'a'; i <= (int)'z'; ++i)
        {
            int minim = INT32_MAX;
            for (int j = 0; j < countChar.size(); ++j)
            {
                minim = min(minim, countChar[j][char(i)]);
            }
            for (int j = 0; j < minim; ++j)
            {
                string temp;
                temp += (char)i;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> s = {"bella", "label", "roller"};
    vector<string> ans = sol.commonChars(s);
    for (string n : ans) cout << n << '\n';
}