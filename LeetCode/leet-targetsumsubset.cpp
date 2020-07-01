#include <bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> combi;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        findCombi(candidates, 0, target);
        return ans;
    }
    
    void findCombi(vector<int>& a, int start, int target)
    {
        if (target < 0)
        {
            return;
        }
        else if (target == 0)
        {
            ans.push_back(combi);
            for (int i = 0; i < combi.size(); ++i)
            {
                cout << combi[i] << ' ';
            }
            cout << endl;
            return;
        }
        else
        {
            //cout << 't' << endl;
            while (start < a.size())
            {
                combi.push_back(a[start]);
                findCombi(a, start, target-a[start]);
                ++start;
                combi.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> ans = sol.combinationSum(arr, 9);
    cout << ans.size() << endl;
}