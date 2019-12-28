#include <bits/stdc++.h>
#include <vector>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}
using ll = long long int;



int main()
{
    list<int> f;
    int n;
    cin >> n;
    int giveto[n];
    bool given[n+1];
    memset(given, 0, sizeof(given));
    for (int i = 0; i < n; i++)
    {
        cin >> giveto[i];
        given[giveto[i]] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        
        if (!given[i])
        {
            f.push_back(i);
        }
    }
    //cout << f.size() << endl;
    int befIndex;
    for (int i = 0; i < n; i++)
    {
        if (giveto[i] == 0)
        {
            if (i+1 == f.back())
            {
                if (f.size() == 1)
                {
                    giveto[i] = f.back();
                    f.pop_back();
                    swap(giveto[i], giveto[befIndex]);
                    befIndex = i;
                    continue;
                }
                int temp = f.back();
                f.pop_back();
                giveto[i] = f.back();
                f.pop_back();
                f.push_back(temp);
                befIndex = i;
                continue;
            }
            giveto[i] = f.back();
            f.pop_back();
            befIndex = i;
        }
    }
    //cout << "t" << endl;
    for (int i = 0; i < n-1; i++)
    {
        cout << giveto[i] << " ";
    }
    cout << giveto[n-1] << '\n';
    return 0;
}
