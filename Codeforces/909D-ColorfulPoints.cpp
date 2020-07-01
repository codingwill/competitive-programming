#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin >> a;
    bool first = false;
    bool adaHapus = false;
    int firstPoint, lastPoint;
    int count = 0;
    while (true)
    {
        first = false;
        firstPoint = 0;
        lastPoint = 0;
        adaHapus = false;
        int pStr = a.length();
        for (int i = 0; i < pStr; i++)
        {
            if ((i == pStr-1) && first)
            {
                lastPoint = i;
                first = false;
                adaHapus = true;
                a.erase(firstPoint, lastPoint-firstPoint+1);
                count++;
                break;
            }
            if ((a[i] != a[i+1]) && !first)
            {
                //cout << a[i+1] << endl;
                firstPoint = i;
                first = true;
            }
            if ((a[i] == a[i+1]) && first)
            {
                //cout << a << endl;
                lastPoint = i;
                first = false;
                adaHapus = true;
                a.erase(firstPoint, lastPoint-firstPoint+1);
                count++;
            } 
        }
        //break;
        if (a == "")
        {
            break;
        }
        else if (!adaHapus)
        {
            //cout << "t" << endl;
            break;
        }
    }
    cout << count << "\n";
}