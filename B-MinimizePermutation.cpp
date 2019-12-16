#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    int n;
    
    while (q--)
    {
        cin >> n;
        cin.ignore();
        int num[n];
        for (int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        int i = 0;
        int j = 0;
        int arraySize = n;
        bool fixed = false;
        while (!fixed)
        {
            while (n > 1)
            {
                for (j = 0; j < arraySize; j++)
                {
                    //cout << j << endl;
                    if (num[j] == i + 1)
                    {
                        if (j != 0)
                        {
                            int temp = num[j];
                            num[j] = num[j-1];
                            num[j-1] = temp;
                            n--;
                        }  
                        break;
                    }
                }
                if (num[i] == i + 1)
                {
                    //cout << i << endl;
                    break;
                }
            cout << "test";   
            }
            i++;
        }
        for (int i = 0; i < arraySize; i++)
        {
            if (i != arraySize - 1)
                cout << num[i] << " ";
            else
                cout << num[i] << endl;
        }
    }
    
    //cout << endl;
    return 0;
}
/*
1
5
5 4 1 3 2
*/