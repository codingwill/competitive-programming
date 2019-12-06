#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;
    cin >> name;
    int len = name.length();
    bool wadahHuruf[26];
    memset(wadahHuruf, false, sizeof(wadahHuruf));
    for (int i = 0; i < len; i++)
    {
        wadahHuruf[name[i] - 'a'] = true;
    }
    int distinct = 0;
    for (int i = 0; i < 26; i++)
    {
        if (wadahHuruf[i] == true)
            distinct++;
    }
    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else if (distinct % 2 == 1)
        cout << "IGNORE HIM!" << endl;
}