#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b = 1, c;
    c = a + b;
    while (c < 1000000000)
    {
        cout << c << endl;
        a = b;
        b = c;
        c = a + b;
    }
}