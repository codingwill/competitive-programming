#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/
 
using namespace std;
using ll = long long int;
vector<map<string, int>> database(10005);
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    vector<vector<string>> query;
    for (int i = 0; i < t; ++i)
    {
        int n, q;
        cin >> n >> q;
        cin.ignore();
        vector<string> temp;
        //dataabse
        for (int j = 0; j < n; ++j)
        {
            string input;
            getline(cin, input);
            string strTemp;
            for (int k = 0; k < input.length(); ++k)
            {
                if (input[k] == ' ')
                {
                    temp.push_back(strTemp);
                    strTemp.clear();
                }
                else
                {
                    strTemp += input[k];
                }
            }
            temp.push_back(strTemp);
            strTemp.clear();
 
            //array to hashmap prefix
            for (int k = temp.size()-1; k >= 0; --k)
            {
                
                for (int l = 0; l <= k; ++l)
                {
                    string key = "";
                    for (int m = l; m <= k; ++m)
                    {
                        key += temp[m];
                        if (m < k)
                        {
                            key += " ";
                        }
                    }
                    //cout << key << endl;
                    ++database[j][key];
                }
            }
            temp.clear();
        }
 
        cout << "Case " << i+1 << ":" << '\n';
        //query
        for (int j = 0; j < q; ++j)
        {
            string input;
            getline(cin, input);
            string strTemp;
            ll count = 0;
            for (int k = 0; k < n; ++k)
            {
                if (database[k][input] > 0) ++count;
            }
            cout << count << '\n';
 
            
        }
    }
 
    
    
}