#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int total = 0;
    vector <int> a;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    if (m - n <= 0)
    {
        for (int i = 0; i < m; i++)
        {
            total += a[i];
        }
        cout << total << endl;
        return 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            total += a[i];
        }
        total += (m-n) * -1 * d;
    }
    cout << total << endl;
    return 0;

}
