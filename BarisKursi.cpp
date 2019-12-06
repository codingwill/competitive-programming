#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    int y;
    cin >> y;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            total = x;
        }
        else
        {
            x += y;
            total += x;
        }
    }
    cout << total << endl;
}