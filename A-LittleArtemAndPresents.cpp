#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int given = floor(n / 3) * 2;
    if (n % 3 > 0)
    {
        given++;
    }
    cout << given << endl;
}