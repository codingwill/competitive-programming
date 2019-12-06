#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

typedef long long ll;
Willy Indrayana Komara;

string hasil;
bool sixDigit = false;

int pangkatBesar(ll operand, int totalKali, ll operandAwal)
{
    if (totalKali == 0)
    {
        hasil = "1";
        return 0;
    }
    if (totalKali == 1)
    {
        hasil = to_string(operand);
        while (hasil.length() < 6 && sixDigit)
        {
            hasil.insert(0, "0");
        }
        return 0;
    }
    if (operand * operandAwal > 999999)
    {
        sixDigit = true;
    }
    pangkatBesar((operand * operandAwal) % 1000000, totalKali-1, operandAwal);
    return 0;
}

int main()
{
    ll a, c;
    int b;
    cin >> a >> b;
    c = a;
    pangkatBesar(a, b, c);
    cout << hasil << endl; 
}