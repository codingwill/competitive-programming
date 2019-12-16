#include <bits/stdc++.h>
#define for(i, n) for(int i = 0; i < (int)(n); i++)
#define lli long long int

using namespace std;

int pekerja[1000005];
int main()
{
    memset(pekerja, 0, sizeof(pekerja));
    int n;
    cin >> n;
    int arr[n];
    int min[n], plus[n];
    int sum = 0;
    int day = 0;
    int sub[n];
    bool valid = true;
    memset(sub, 0, sizeof(sub));
    for (i, n)
    {
        cin >> arr[i];
        int index = abs(arr[i]);
        sum += arr[i];
        if (pekerja[index] > 2 && partial_sum)
        {
            cout << "tes" << endl;
            valid = false;
        }
        pekerja[index]++;
        
        sub[day]++;
        if (sum == 0)
        {
            day++;
        }
    }
    
    if (sum == 0 && valid)
    {
        cout << day << "\n";
        for (i, day)
        {
            if (i != day-1)
                cout << sub[i] << " ";
            else
                cout << sub[i] << "\n";
        }
    }
    else
    {
        cout << "-1" << "\n";
    }
    
}