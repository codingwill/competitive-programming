#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int compress[n];
    lli sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int bef, af;
        cin >> bef >> af;
        compress[i] = bef-af;
        sum += bef;
    }
    sort(compress, compress+n, besarDulu);
    int i = 0;
    
    while (sum > m && i < n)
    {
        sum -= compress[i];
        count++;

        i++;
    }
    if (sum > m)
        count = -1;
    cout << count << '\n';
    return 0;
}