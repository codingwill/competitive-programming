#include <bits/stdc++.h>

using namespace std;
unsigned long long int memo[10000];


unsigned long long int Fib(long int a)
{
    if (memo[a] != 0)
       return memo[a];
    if (a <= 1)
        return a;
    unsigned long long int fib = Fib(a-1) + Fib(a-2);
    memo[a] = fib;
    //scout << memo[12] << endl;
    return fib;
}

int main()
{
    memset(memo, 0, sizeof(memo));
    int indexFib = 120;
    cout << Fib(indexFib);
    return 0;
}
