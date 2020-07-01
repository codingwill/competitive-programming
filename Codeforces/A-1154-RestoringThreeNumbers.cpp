#include <bits/stdc++.h>

using namespace std;

int main()
{
    int set[4];
    cin >> set[0] >> set[1] >> set[2] >> set[3];
    sort(set, set+4);
    int x[3];
    for (int i = 0; i < 3; i++)
    {
        x[i] = set[3] - set[i];
    }
    cout << x[0] << " " << x[1] << " " << x[2] << "\n";
}