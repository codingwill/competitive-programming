#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, hasil = 0;
    cin >> a >> b;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        hasil++;
    }
    cout << hasil << "\n";
    return 0;
}