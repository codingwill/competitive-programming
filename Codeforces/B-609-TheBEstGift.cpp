#include <bits/stdc++.h>

#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

#define for(i, n, k) for(int i = (int) (k); i < (int) (n); i++)


int main()
{
    int n, m;
    cin >> n >> m;
    int container[m+1];
    memset(container, 0, sizeof(container));
    for (i, n, 0)
    {
        int input;
        cin >> input;
        container[input]++;
    }
    int hasil = 0;
    for (i, m, 0)
    {
        for (j, m+1, i+1)
        {
            hasil += container[i]*container[j];
        }
    }
    cout << hasil << endl;
    return 0;

}