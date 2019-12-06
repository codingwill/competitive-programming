#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    double best;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        double harga = x * (m / y);
        if (i > 0)
        {
            best = min(best, harga);
        }
        else
        {
            best = harga;
        }
    }
    cout << setprecision(9) << best << endl;
    return 0;
}
