#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans;
    string hasil = "EASY";
    for (int i = 0; i < n; i++)
    {
        cin >> ans;
        if (ans == 1)
            hasil = "HARD";
    }
    cout << hasil << "\n";
    return 0;
}
