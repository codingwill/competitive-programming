#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int c[3];
    while (t--)
    {
        cin >> c[0] >> c[1] >> c[2];
        sort(c, c+3);
        int count = 0;
        if (c[0] == c[1] == c[2])
        {
            count = (c[0] / 2) * 3 + 1;
        }
        else if (c[1] == c[2])
        {
            count = c[1] + 1;
        }
        /*
        else if (c[0] == c[1])
        {
            count = min(c[2], c[1]);
        }
        */
        else
        {
            for (int i = 0; i < 2; i++)
            {
                count += c[i];
                c[2] = c[2] - c[i];
                c[i] = 0;
                sort(c, c+3);
            }
        }
        cout << count << "\n";
    }
    return 0;
}