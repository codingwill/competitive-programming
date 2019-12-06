#include <bits/stdc++.h>

using namespace std;

int arr[10][100000000];

int main()
{
    memset(arr, 0, sizeof(arr));
    arr[8][99999999] = 2;
    cout << arr[8][99999998] << endl;
}