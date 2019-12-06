#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int k[n];
    int minim;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = 0; j < k[i]; j++)
        {
            cin >> m;
            total += m * 5;
        }
        total += k[i] * 15;
        if (i == 0)
            minim = total;
        else
        {
            minim = min(minim, total);
        }
    }
    cout << minim << endl;
    return 0;
}