#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;

/*
 * Complete the 'receivedText' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING S as parameter.
 */
list<string> ans;
string temp, res;


string receivedText(string s) {
    // WRITE DOWN YOUR CODE HERE
    
    bool home = false;
    bool num = true;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '<') 
        {
            if (!temp.empty())
            {
                if (home) ans.push_front(temp);
                else ans.push_back(temp);
                temp.clear();
            }
            home = true;
        }
        else if (s[i] == '>') 
        {
            if (!temp.empty())
            {
                if (home) ans.push_front(temp);
                else ans.push_back(temp);
                temp.clear();
            }
            home = false;
        }
        else if (s[i] == '#') num = !num;
        else if (s[i] == '*')
        {
            if (!temp.empty())
            {
                temp.pop_back();
            }
            else
            {
                if (!home)
                {
                    if (!ans.empty())
                    {
                        temp = ans.back();
                        temp.pop_back();
                        ans.pop_back();
                    }
                }
                
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            if (num)
            {
                temp.push_back(s[i]);
            }
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    if (!temp.empty())
    {
        if (home) ans.push_front(temp);
        else ans.push_back(temp);
        temp.clear();
    }
    
    for (auto n : ans)
    {
        res += n;
    }
    
    return res;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string S;
    getline(cin, S);

    string result = receivedText(S);

    cout << result << "\n";

    return 0;
}

/*
ABCDE<<FGH**IJK>>>>>><L>>MNOP*****
LFGHIJKABCDE
LFIJKABCD
LFIJKABCD
*/