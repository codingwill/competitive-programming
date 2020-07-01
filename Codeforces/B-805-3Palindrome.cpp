#include <bits/stdc++.h>

using namespace std;

/*
abbaabbaabbaabb
*/

int main()
{
    int n;
    cin >> n;
    int j = 0, k = 0;;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (j % 2 == 0)
            {
                cout << "a";
            }
            else
            {
                cout << "b";
            }
            j++;
        }
        else
        {
            if (j % 2 == 0)
            {
                cout << "b";
            }
            else
            {
                cout << "a";
            }
            k++;
        }
    }
    cout << "\n";
    return 0;
}