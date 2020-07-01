#include <bits/stdc++.h>

using namespace std;

//  1 3 7 14 25 41
// 1 2 4 7 11 16
//0 1 2 3 4  5

int main()
{
    int n;
    cin >> n;
    int count = 0;
    int hasil = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        hasil += i;
        ans += hasil;
    }

    cout << ans << "\n";
}