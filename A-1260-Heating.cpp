#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int sum;
        int c;
        cin >> c >> sum;
        float sumF = sum, cF = c;
        int pair[2];
        pair[0] = floor(sumF/cF);
        pair[1] = ceil(sumF/cF);
        int himpunanBawah = sum % c;
        int a = pair[0] * pair[0];
        int b = pair[1] * pair[1];
        int hasil;
        if (sum > c)
        {
            hasil = (a*himpunanBawah) + (b*(c-himpunanBawah));
        }
        else
        {
            hasil = (b*sum);
        }
        
        cout << hasil << endl;
    }
}