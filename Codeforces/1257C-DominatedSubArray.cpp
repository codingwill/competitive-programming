#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    int arr[200005];
    int count[200005];
    while (t--)
    {
        memset(count, 0, sizeof(count));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            count[arr[i]]++;
        }
        if (n == 1)
        {
            cout << "-1" << endl;
            continue;
        }
        int maks = 0;
        int maksValue;
        for (int i = 1; i < 200005; i++)
        {
            if (maks < count[i])
            {
                maks = count[i];
                maksValue = i;
            }
            

        }
        int point[maks];
        int iPoint = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maksValue)
            {
                point[iPoint] = i;
                iPoint++;
            }
        }
        int maksDiff = 100000000;
        sort(point, point+maks);
        for (int i = 0; i < maks - 1; i++)
        {
            maksDiff = min(maksDiff, point[i+1] - point[i] + 1);
        }
        cout << maksDiff << endl;
    }
}