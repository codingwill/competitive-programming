#include <bits/stdc++.h>

using namespace std;
/*
int luckyCombi(int lucky[], int i, int level, int kombi)
{
    int number = level * lucky[i];
    if (number)
}
*/
void minLucky(int n4, int n7)
{
    for (int i = 0; i < n4; i++)
    {
        cout << "4";
    }
    for (int i = 0; i < n7; i++)
    {
        cout << "7";
    }
}
int main()
{
    //int lucky[2] = {4, 7};
    int n;
    cin >> n;
    //int awal = n / 7;
    int batasAkhir = n / 4;
    int batasAwal = n / 7;
    int sum = 0;
    int batas = batasAkhir - batasAwal;
    for (int j = 0; j <= batas; j++)
    {
        for (int i = 0; i <= batasAwal + j; i++)
        {
            sum = (batasAwal+j-i)*7 + i*4;
            //cout << batasAkhir-i << endl;
            if (sum == n)
            {
                minLucky(i, (batasAwal+j-i));
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "-1" << "\n";
    return 0;
}