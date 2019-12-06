#include <bits/stdc++.h>
#define ll long long

using namespace std;
//bool prime[1000000000];

int main()
{
    int t;
    cin >> t;
    ll int x, y;
    while (t--)
    {
        cin >> x >> y;
        while (true)
        {
            if (x == y || (x != 1 && x > y))
            {
                cout << "YES" << endl;
                break;
            }
            if (x != y && x == 1)
            {
                cout << "NO" << endl;
                break;
            }
            if (x % 2 == 0 && x < y)
            {
                x = x/2 * 3;
            }
            else if (x > 1 && x != 3)
            {
                x -= 1;
            }
            else
            {
                cout << "NO" << endl;
                break;
            }
            //cout << x << endl;
        }
        
    }
    return 0;
    


}
