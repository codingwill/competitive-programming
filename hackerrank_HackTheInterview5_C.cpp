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
string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMaxScore' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING jewels as parameter.
 */

int getMaxScore(string jewels) 
{
    stack<char> stk;
    ll count = 0;
    for (int i = 0; i < jewels.length(); ++i)
    {
        if (!stk.empty())
        {
            if (stk.top() == jewels[i])
            {
                stk.pop();
                ++count;
            }
            else 
                stk.push(jewels[i]);
        }
        else
        {
            stk.push(jewels[i]);
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string jewels;
        getline(cin, jewels);

        int ans = getMaxScore(jewels);

        fout << ans << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) 
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) 
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


/*
ABCDE<<FGH**IJK>>>>>><L>>MNOP*****
LFGHIJKABCDE
LFIJKABCD
LFIJKABCD
*/