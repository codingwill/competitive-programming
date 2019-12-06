#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a >= 0)
        {
            sum += a;
        }
        else
        {
            sum -= a;
        }
        
    }
    cout << sum << endl;

    return 0;
}