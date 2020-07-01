#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;


using ll = long long int;

void solve(int a, int b)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll hasil = 1;
    
    for (ll i = a+1; i <= b; i++)
    {
        hasil = (hasil * i) % 10;
        if (hasil == 0)
        {
            break;
        }
    }
    cout << hasil << '\n';
    return 0;
}
//10! = 0
//masalah a = 0 b = 10^18 TLE