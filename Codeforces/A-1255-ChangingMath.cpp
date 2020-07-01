#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << (abs(a-b) / 5) + ((abs(a-b) % 5) / 2) + ((abs(a-b) % 5) % 2) << "\n";
    }
    return 0;
}