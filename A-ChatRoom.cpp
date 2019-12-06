#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    string hello = "hello";
    int len = input.length();
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] == hello[j])
        {
            j++;
            if (j == 5)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}