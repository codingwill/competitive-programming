#include <bits/stdc++.h>

using namespace std;

unsigned long long int Fib(long int a)
{
    if (a <= 1)
        return a;
    return Fib(a-1) + Fib(a-2);
}
int main()
{
    int indexFib = 50;
    cout << Fib(indexFib);
    return 0;
}