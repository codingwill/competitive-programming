#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
int a[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    ll v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;

    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        ll minus = 0, plus = 0, nol = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < 0)
            {
                minus++;
            }
            else if (a[i][j] > 0)
            {
                plus++;
            }
            else 
            {
                nol++;
            }
            sum += abs(a[i][j]);
        }
        if (minus + nol > plus)
        {
            if (v1 < 0)
            {
                sum += abs(minus*v1) + abs(nol*v1) - abs(plus*v1);
            }
        }
        else if (minus < nol + plus)
        {
            if (v1 > 0)
            {
                sum += abs(plus*v1) + abs(nol*v1) - abs(minus*v1);
            }
        }
        sum = max(sum, (ll)abs(v2*m));
        total += sum;
    }

    ll total2 = 0;
    for (int i = 0; i < m; i++)
    {
        ll sum = 0;
        ll minus = 0, plus = 0, nol = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] < 0)
            {
                minus++;
            }
            else if (a[j][i] > 0)
            {
                plus++;
            }
            else 
            {
                nol++;
            }
            sum += abs(a[j][i]);
        }
        if (minus + nol > plus)
        {
            if (v3 < 0)
            {
                sum += abs(minus*v3) + abs(nol*v3) - abs(plus*v3);
            }
        }
        else if (minus < nol + plus)
        {
            if (v3 > 0)
            {
                sum += abs(plus*v3) + abs(nol*v3) - abs(minus*v3);
            }
        }
        sum = max(sum, (ll)abs(v4*n));
        //cout << sum << endl;
        total2 += sum;
    }

    cout << max(total, total2) << endl;
    return 0;
}
/*
2 2
-5 8 -2
6 -9
-2 5 -1 6

sum = sum + nMinus*v - nPlus*v
*/