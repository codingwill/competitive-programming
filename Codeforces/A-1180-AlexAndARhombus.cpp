#include <bits/stdc++.h>

using namespace std;

int barisanKe(int i)
{
    if (i == 1)
        return 1;
    return barisanKe(i-1) + (2*i + 2*(i-2));
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << "\n";
        return 0;
    }
    cout << barisanKe(n) << "\n";
    return 0;
}