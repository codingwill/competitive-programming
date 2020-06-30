#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/28
*/

using namespace std;
using ll = long long int;

bool byLevel(const pair<string, string> &a, const pair<string, string> &b)
{
    
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length()) return a.first < b.first; 
        return a.first.length() < b.first.length();
    }
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        vector<pair<string, string>> name(0);
        vector<string> ans(0);
        set<string> nameExist(0);
        for (int i = 0; i < n; ++i)
        {
            string input;
            getline(cin, input);
            string people = "", temp = "";
            bool nameDone = false;
            string levelTemp = "";
            for (int j = 0; j < input.length(); ++j)      
            {
                if (!nameDone)
                {    
                    if (input[j] == ':')
                    {
                        nameDone = true;
                        ++j;
                    }
                    else
                    {
                        people += input[j];
                    }
                }
                else
                {
                    if (input[j] != '-' && input[j] != ' ') temp += input[j];
                    else
                    {
                        if (temp == "upper") levelTemp.insert(0, "3");
                        else if (temp == "middle") levelTemp.insert(0, "2");
                        else if (temp == "lower") levelTemp.insert(0, "1");
                        temp = "";
                    }
                }
            }
            //cout << levelTemp.length() << endl;
            int levelLen = levelTemp.length();
            for (int j = 0; j < 15-levelLen; ++j)
            {
                levelTemp.push_back('0');
            }
            name.push_back(make_pair(people, levelTemp));
        }
        sort(name.begin(), name.end(), byLevel);

        for (int i = 0; i < )

        for (pair<string, string> n : name)
        {
            cout << n.first << '\n';
        }
        for (int x = 0; x < 30; ++x)
        {
            cout << '=';
        }
        cout << '\n';
    }
}