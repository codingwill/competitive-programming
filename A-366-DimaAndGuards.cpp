#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[4][2], b[4][2];
    int kombi;
    for (int k = 0; k < 4; k++)
    {
        cin >> a[k][0] >> a[k][1] >> b[k][0] >> b[k][1];
    }
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                kombi = a[k][i] + b[k][j];
                //cout << kombi << endl;
                if (kombi <= n)
                {
                    cout << k+1 << " " << a[k][i] << " " << (n-a[k][i]) << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1" << endl;
    
}