#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int len = input.length();
    int hitung = 1;
    bool bahaya = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] == input[i-1])
        {
            hitung++;
        }
        else
        {
            hitung = 1;
        }
        if (hitung >= 7)
        {
            bahaya = true;
            break;
        }
    }
    if (bahaya)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}