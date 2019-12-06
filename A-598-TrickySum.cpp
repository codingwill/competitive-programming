#include <bits/stdc++.h>
#define lli long long int
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        lli n;
        cin >> n;
        lli duaPangkat = log2(n);
        lli hasil = 0;
        rep(i, duaPangkat + 1)
        {
            hasil -= (lli)pow(2, i);
        }
        //cout << hasil << endl;
        cout << (lli)(((double)n/2)*(1 + n)) + (2*hasil) << endl; 
    }
}