#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n , x, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> a >> b;
        int kecil = min(a, b);
        int besar = max(a, b);
        //x = round((float)x / 2);
        int potDiff = abs(kecil-0) + abs(besar-n);
        int jarak;
        //cout << besar << " " << kecil << endl;
        if (potDiff <= x)
        {
            cout << n - 1 << endl;
        }
        else
        {
            jarak = abs((besar + x) - kecil);
            cout << jarak << endl;
        }
        
    }
    return 0;
}