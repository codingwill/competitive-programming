#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string answer = "";
    string largestTimeFromDigits(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        if (A[min_element(A.begin(), A.end()) - A.begin()] > 2) return "";
        int maximum = -1;
        do
        {
            /*
            for (int i = 0; i < A.size(); ++i)
            {
                cout << A[i] << ' ';
            }
            cout << endl;
            */
            int hour = (A[0]*10 + A[1]);
            int minutes = (A[2]*10 + A[3]);
            if (!(hour > 23 || minutes > 59))
            {
                int total_minutes = hour*60 + minutes;
                //cout << total_minutes << endl;
                maximum = max(maximum, total_minutes);
            }
        }
        while (next_permutation(A.begin(), A.end()));
        if (maximum == -1) return "";
        answer += to_string(maximum/60) + to_string(maximum % 60);
        //cout << answer << endl;
        answer.insert(0, (maximum / 60 < 10 ? "0" : ""));
        //cout << answer << endl;
        answer.insert(answer.size()-1, (maximum % 60 < 10 ? "0" : ""));
        //cout << answer << endl;
        answer.insert(2, ":");
        return answer;
    }
};

int main()
{
    Solution sol;
    vector<int> a{4, 1, 0, 0};
    cout << sol.largestTimeFromDigits(a);

}