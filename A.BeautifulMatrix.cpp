#include <bits/stdc++.h>

using namespace std;

int main()
{
    int input;
    int baris, kolom;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> input;
            if (input == 1)
            {
                baris = i;
                kolom = j;
            }
        }
    }
    cout << abs(baris - 2) + abs(kolom - 2) << endl;
}