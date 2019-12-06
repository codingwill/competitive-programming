#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int len = input.length();
    int buatSorting[len];
    int indexAngka = 0;
    for (int i = 0; i < len; i++)
    {
        if (input[i] != '+')
        {
            buatSorting[indexAngka] = input[i] - '0';
            indexAngka++;
        }
    }
    sort(buatSorting, buatSorting+((len+1) / 2));
    indexAngka = 0;
    for (int i = 1; i <= len; i++)
    {
        if (i % 2 == 1)
        {
            cout << buatSorting[indexAngka];
            indexAngka++;
        }
        else
        {
            cout << "+";
        }
        
    }
    cout << endl;
}