#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int subX = 0;
    int count = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
        {
            subX++;
        }
        else
        {
            if (subX >=3)
                count += abs(subX - 2);
            subX = 0;
        }
        if (i == n-1)
        {
            if (subX >= 3)
                count += abs(subX - 2);
        }
    }
    cout << count << "\n";
    return 0;

}