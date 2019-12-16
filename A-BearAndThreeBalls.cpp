#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        t.push_back(input);
    }
    sort(t.begin(), t.end());
    for (int i = 0; i < n-2; i++)
    {
        int j = i + 1, k = i + 2;
        while (abs(t[i] - t[j]) != 1 && j <= n - 1)
        {
            j++;
            k++;
        }
        while (abs(t[j] - t[k]) != 1 && k <= n)
        {
            k++;
        }
        if (abs(t[i] - t[j]) == 1 && abs(t[j] - t[k]) == 1) 
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}