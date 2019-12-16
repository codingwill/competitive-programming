#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'O')
        {
            count++;
        }
    }
    if (count == 1)
    {
        cout << "Ya" << endl;
    }
    else
    {
        cout << "Tidak" << endl;
    }
    return 0;
}