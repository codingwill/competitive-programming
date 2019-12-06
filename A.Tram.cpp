#include <bits/stdc++.h>

using namespace std;

int main()
{
    int stops;
    cin >> stops;
    int naik = 0, turun = 0;
    int currentP = 0, maxP = 0;
    for (int i = 0; i < stops; i++)
    {
        cin >> turun >> naik;
        currentP = currentP + naik - turun;
        if (i == 0)
        {
            maxP = currentP;
        }
        else
        {
            maxP = max(currentP, maxP);
        }
    }
    cout << maxP << endl;
}