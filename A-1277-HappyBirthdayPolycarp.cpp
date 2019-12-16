#include <bits/stdc++.h>

using namespace std;

int nilai;
int beauArr[81];

int beautiful(int angka, int digit)
{
    if (digit == 0) return angka; 
    return pow(10, digit)*angka + beautiful(angka, digit-1);
}

void beautifulList()
{
    int k = 0;
    for (int i = 0; i <= 8; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            beauArr[k] = beautiful(j, i);
            k++;
        }
    }    
}

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    beautifulList();
    while (t--)
    {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 0; i < 81; i++)
        {
            if (n >= beauArr[i])
            {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
    
}
