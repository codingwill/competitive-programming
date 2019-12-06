#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x[3];
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x+3);
    if (x[0] == x[1] && x[2] - x[1] < x[0]  && x[0] < x[2] + x[1])
    {
        if (x[2] - x[1] == 1)
        {
            cout << "Ya" << endl;
            return 0;
        }
        else
        {
            cout << "Tidak" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Tidak" << endl;
        return 0;
    }
    
}