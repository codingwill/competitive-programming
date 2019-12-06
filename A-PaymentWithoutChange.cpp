#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int q;
    cin >> q;
    while (q--)
    {
        long long int a, b, n, S;
        cin >> a >> b >> n >> S;
        if (a * n + b >= S)
        {
            if ((S % n) - b <= 0)
            { 
                cout << "YES" << endl;
                continue;   
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}