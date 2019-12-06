#include <bits/stdc++.h>

using namespace std;

//1000000000
/*
1-9 = 9; -> 1 * (n + 1 - 1)
10-19 = 2 * 10 = 20 
10-99 = 2 * 10 * 9 = 180; -> 2 * (n + 1 - 10)
1-99 = {1-9} + {10-99} = 9 + 180 = 189 
100-999 -> 3 * (n + 1 - 100)

if n = 13
2 * (13 + 1 - 10) = 2 * 4 = 8
1 * ()
*/

int Sembilan(int n)
{
    if (n == 0)
        return 9;
    int hasil;
    hasil = pow(10, n) * 9 + Sembilan(n - 1);
    return hasil;
}

int main()
{
    long long int kelDigit[9];
    string n;
    cin >> n; //100
    int len = n.length();
    long long int nInt = stoi(n);
    int j = 0;
    long long int hasil = 0;
    for (int i = 0; i < len - 1; i++)
    {
        kelDigit[i] = Sembilan(i);
        hasil += (i + 1) * (kelDigit[i] + 1 - pow(10, i)); 
        //9
    }
    nInt = nInt - (int)pow(10, len - 1) + 1; //
    //cout << kelDigit[0] << endl;
    hasil += (nInt * len);
    cout << hasil << endl;
    return 0;
}
