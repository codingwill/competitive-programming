#include <bits/stdc++.h>
/*
by: wkwkwill
date: 2020/07/08
*/

using namespace std;

class Solution 
{
private:


public:
    bool wordPattern(string pattern, string str)
    {
        map<char, string> patternKey;
        map<string, char> strKey;
        set<char> keyGiven;
        string temp = "";
        int iPattern = 0;
        for (int i = 0; i < str.length(); ++i)
        {  
            if (str[i] != ' ')
            {
                temp.push_back(str[i]);
            }
            else
            {
                //cout << patternKey.count(pattern[iPattern]) << ' ' << strKey.count(temp) << '\n';
                //cout << patternKey[pattern[iPattern]] << '\n';
                if ((patternKey.count(pattern[iPattern])) < 1 && (strKey.count(temp) < 1))
                {
                    strKey[temp] = pattern[iPattern];
                    patternKey[pattern[iPattern]] = temp;
                }
                else
                {
                    cout << "t\n";
                    if (patternKey[pattern[iPattern]] != temp || strKey[temp] != pattern[iPattern])
                    {
                        return false;
                    }
                }
                iPattern++;
                temp = "";
            }
        }
        //cout << patternKey[pattern[iPattern]] << '\n';
        if (keyGiven.find(pattern[iPattern]) == keyGiven.end())
        {
            keyGiven.insert(pattern[iPattern]);
            patternKey[pattern[iPattern]] = temp;
        }
        else
        {
            if (patternKey[pattern[iPattern]] != temp)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    sol.wordPattern("abba", "dog cat cat dog") ? cout << "true" : cout << "false";
}