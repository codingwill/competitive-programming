#include <bits/stdc++.h>

#define for(i, n) for(int i = 0; i < (int)(n); i++)
#define lli long long int

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l, r, k;
        int a[n], b[n], c[n];
        int bisaNambah[100000];
        bool yesNo = true;
        int index = 0;
        for (i, n)
        {
            cin >> a[i];
        }
        for (i, n)
        {
            cin >> b[i];
            if (a[i] == b[i])
            {
                continue;
            }
            if (a[i] > b[i])
            {
                yesNo = false;
                break;
            }
            if (a[i] < b[i])
            {
                bisaNambah[index] = i;
                index++;
            }
        }
        sort(bisaNambah, bisaNambah+index);

        if (yesNo)
        {
            for (i, index-1)
            {
                //cout << "ts" << endl;
                if (bisaNambah[i+1] - bisaNambah[i] > 1)
                {
                    
                    yesNo = false;
                    break;
                }
            }
        }
        if (yesNo)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";   
    }
    return 0;
}