#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int diff = 0;
    int slen = a.length();
    for (int i = 0; i < slen; i++)
    {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
        //diff += (a[i] - b[i]);
        if (a[i] > b[i])
        {
            diff = 1;
            break; 
        }
        else if (a[i] < b[i])
        {
            diff = -1;
            break;
        }
    }
    if (diff < 0)
        cout << "-1" << endl;
    else if (diff == 0)
        cout << "0" << endl;
    else
        cout << "1" << endl;
}