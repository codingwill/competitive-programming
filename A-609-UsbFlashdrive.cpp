#include <bits/stdc++.h>

using namespace std;

bool besarDulu(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n, besarDulu);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count >= m)
        {
            cout << i << endl;
            return 0;
        }
        count += a[i];
    }
    cout << n << endl;
    return 0;
}