#include <bits/stdc++.h>

using namespace std;
bool point[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m; 
    int sum = m;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            if (!point[i])
            {
                sum--;
                point[i] = true;
            }
        }
    }
    if (sum == 0)
    {
        cout << sum << '\n';
        return 0;
    }
    cout << sum << '\n';
    for (int i = 1; i <= m; i++)
    {
        if (point[i]) continue;
        if (i == m) cout << i << '\n';
        else cout << i << ' ';
    }
    return 0;
}