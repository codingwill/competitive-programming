#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;
unordered_map<string, ll> database(3000000);


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    vector<vector<string>> query;
    vector<vector<ll>> ans;
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
            map<string, ll> sudahAda;
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

            //array to hashmap suffix
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
                    if (sudahAda[key] <= 0) 
                    {
                        ++database[key];
                        ++sudahAda[key];
                    }
                    //cout << key << endl;
                        
                }
            }
            sudahAda.clear();
            temp.clear();
        }

        //query
        vector<ll> subAns;
        for (int j = 0; j < q; ++j)
        {
            string input;
            getline(cin, input);
            string strTemp;
            ll count = 0;
            subAns.push_back(database[input]);
        }
        ans.push_back(subAns);
        subAns.clear();
        database.clear();
    }
    for (int i = 0; i < t; ++i)
    {
        cout << "Case " << i+1 << ":" << '\n';
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << '\n';
        }
    }
    
}

/*
1
5
1
a b c d e
bajsdj bajsdb
a a aa a a
ajskdaj jkas djkasd k
ad askdjaskdjka aaa  ba baba a a
a a
Case 1:
0
*/
