#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    vector<int> partitionLabels(string s) 
    {
        
        int l = 0, r = s.length()-1;
        int found = 0;
        set<char> count;
        vector<int> ans;
        int start = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i > found) 
            {
                ans.push_back(i - start);
                start = i;
            }
            r = s.length()-1;
            if (count.find(s[i]) != count.end()) continue;
            //cout << 't' << endl;
            count.insert(s[i]);
            while (r > found)
            {
                if (s[i] == s[r])
                {
                    found = r;
                    break;
                }
                --r;
            }
        }
        ans.push_back(s.length() - start);
        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    cin >> s;
    vector<int> ans = sol.partitionLabels(s);
    for (int n : ans) cout << n << ' ';
}