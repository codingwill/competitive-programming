#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/20
*/
using namespace std;
using ll = long long int;


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
        vector<int> even, odd;
        for (int i = 0; i < n*2; ++i)
        {
            int input;
            cin >> input;
            if (input % 2 == 0)
                even.push_back(i+1);
            else
                odd.push_back(i+1);
        }
        int i = 0;
        int count = 0;
        if (!odd.empty())
        {
            while (count < n-1 && i <= odd.size()-2)
            {
                cout << odd[i] << ' ' << odd[i+1] << '\n';
                i += 2; 
                ++count;
            }
        }
        
        i = 0;
        if (!even.empty())
        {
            //cout << 't' << endl;
            while (count < n-1 && i <= even.size()-2)
            {
                cout << even[i] << ' ' << even[i+1] << '\n';
                i += 2;
                ++count;
            }
        }
       
    }
}