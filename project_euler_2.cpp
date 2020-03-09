#include <bits/stdc++.h>

using namespace std;

int main()
{
    int total = 2, a, b = 2, c = 1; //a = f(n) = f(n-1) + f(n-2) = b + c, b = f(n-1), c = f(n-2), total = sum of even valued f(n)
    a = b + c;
    while (a < 4000000)
    {
        if (a % 2 == 0)
        {
            total = total + a;
        }
        c = b;
        b = a;
        a = b + c;
    }
    
    cout << total << '\n';
}