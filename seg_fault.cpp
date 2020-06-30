#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/11
*/
using namespace std;

int main()
{
    int a[4] = {1, 5, 9, 6};
    int* x;
    x = a;
    *x = 2;
    cout << *x << ' ' << a[0] << endl;
    cout << x << ' ' << &a << endl;
    x++;
    cout << *x << ' ' << a[1] << endl;
    cout << x << ' ' << &a[1] << endl;
    x++;
    cout << *x << ' ' << a[2] << endl;
    cout << x << ' ' << &a[2] << endl;
    x++;
    cout << *x << ' ' << a[3] << endl;
    cout << x << ' ' << &a[3] << endl;
    x++;
    return 0;
}
