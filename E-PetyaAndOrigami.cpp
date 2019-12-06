#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n;
    long long int k;
    cin >> n >> k;
    cout << (int)(ceil(n*2 / k) + ceil(n*5 / k) + ceil(n*8 / k)) << endl;
    return 0;
}