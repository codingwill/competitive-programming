#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool checkPalindrome(vector<int> num){
    int size_num = num.size();
    bool status = true;

    for (int i = 0; i < size_num ; i++)
    {
        vector<int>::iterator it = num.begin() + i;
        vector<int>::reverse_iterator rit = num.rbegin() + i;
        if (*it != *rit){
            status = false;
            break;
        }
    }
    
    return status;
}

int main(){
    int N;
    cin >> N;
    vector<int> Vector;

    while (N--)
    {
        int num_input;
        cin >> num_input;
        Vector.push_back(num_input);
    }

    if (checkPalindrome(Vector))
    {
        cout << 0 << endl;
    }else {
        int differ = 0;
        int size_num = Vector.size();
        for (int i = 0; i < size_num ; i++)
        {
            vector<int>::iterator it = Vector.begin() + i;
            vector<int>::reverse_iterator rit = Vector.rbegin() + i;
            if (*it != *rit){
                differ++;
            }
        }

        cout << differ-1 << endl;
    }
    

}