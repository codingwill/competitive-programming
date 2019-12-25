#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
bool besarDulu(const int &a, const int &b)
{
    return a > b;
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;
        long long int penambah = 1;
        long long int count = 0;
        while (a != b)
        {
            if (a < b)
            {
                if (a + penambah > b)
                {
                    b += penambah;
                    penambah++;
                    count++;
                    //continue;
                }
                a += penambah;
                penambah++;
                count++;
            }
            else if (b < a)
            {
                if (b + penambah > a)
                {
                    a += penambah;
                    penambah++;
                    count++;
                    //continue;
                }
                b += penambah;
                penambah++;
                count++;
            }
        }
        cout << count << endl;
    }
}