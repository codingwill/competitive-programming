#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        if (a[0] == a[1] && a[1] == a[2])
        {
            cout << "0" << "\n";
            continue;
        }
        sort(a, a+3);
        if (a[0] != a[1])
        {
            ++a[0];
        }
        else
        {
            ++a[0];
            ++a[1];   
        }
        if (a[0] == a[1] && a[1] == a[2])
        {
            cout << "0" << "\n";
            continue;
        }
        if (a[1] != a[2])
        {
            --a[2];
        }
        else
        {
            --a[1];
            --a[2];  
        }
        if (a[0] == a[1] && a[1] == a[2])
        {
            cout << "0" << "\n";
            continue;
        }
        cout << (abs(a[0]-a[1]) + abs(a[0]-a[2]) + abs(a[1]-a[2])) << "\n";
    }
    return 0;
}