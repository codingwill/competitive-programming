#include <bits/stdc++.h>

using namespace std;

long knapsack(long currW, long w[], long v[], long n)
{
    long x, a, b;
    if(n == 0 || currW == 0)
        return 0;

    if (w[n-1] > currW)
    {
    	cout << 't' << endl;
        x = knapsack(currW, w, v, n-1);
        return x;
    }    
    else
    {
        a = v[n-1] + knapsack(currW - w[n-1], w, v, n-1);
        b = knapsack(currW, w, v, n-1);
        x = max(a, b);
        return x;
    }
    
}

int main()
{
    long currW = 160;
    long v[] = {200, 300, 500, 10};
    long w[] = {20, 50, 100, 50};
    long n = sizeof(w) / sizeof(w[0]);

    cout << knapsack(currW, w, v, n);

}
