#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    string codeWord = "CODEFORCES";
    int j = 0;
    int total = 0;
    bool substringBaru = false;
    int totalSubs = 0;
    //cout << input.length() << endl;
    if (codeWord.length() > input.length())
    {
        cout << "NO" << endl;
        return 0;
    }

    if (input.find(codeWord) == 0 || input.find(codeWord) == input.length() - codeWord.length())
    {
        cout << "YES" << endl;
        return 0;
    }

    for (int i = 0; i < codeWord.length() - 1; i++)
    {
        int lastIndex = (input.length()) - codeWord.length() + i + 1;
        //cout << input.find(codeWord.substr(i + 1, codeWord.length() - i - 1)) << endl;
        if (input.find(codeWord.substr(0, i + 1)) == 0 
            && codeWord.substr(i + 1, codeWord.length() - i - 1) 
            == input.substr(lastIndex, codeWord.length() - i - 1)
           )
        {
            cout << "YES" << endl;
            return 0;
        }
        
    }
    cout << "NO" << endl;
    return 0;
}