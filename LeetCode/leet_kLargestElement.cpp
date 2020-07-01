#include <bits/stdc++.h>

using namespace std;

class KthLargest 
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
    KthLargest(int k, vector<int>& nums) {
        if (nums.size() > 0)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                pq.push(nums[i]);
            }
            for (int i = 0; i < nums.size()-k; ++i)
            {
                pq.pop();
                cout << (int)nums.size()-k << endl;
            }
        }
        count = k;
        
    }
    
    int add(int val) 
    {
        pq.push(val);
        if (pq.size() > count)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    vector<int> nums{0};
    KthLargest kth(2, nums);
    cout << kth.add(-1) << endl;
}
/*
8 5 4
8 5 4
8 5 5
*/
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */