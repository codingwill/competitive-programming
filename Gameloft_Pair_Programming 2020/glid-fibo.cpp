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

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;
const int MAX = 1000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> fibo;
    int a = 1, b = 1;
    fibo.push_back(a);
    fibo.push_back(b);
    int p = 1;
    while (fibo[p] <= MAX)
    {
        //cout << fibo[p] << endl; 
        fibo.push_back(fibo[p] + fibo[p-1]);
        p++;
    }

    int t;
    cin >> t;

    while (t--)
    {
        bool dekat = false;
        int input;
        cin >> input;
   
        int it = lower_bound(fibo.begin(), fibo.end(), input) - fibo.begin();
        int it2 = upper_bound(fibo.begin(), fibo.end(), input) - fibo.begin();
        //cout << fibo[it] << ' ' << fibo[it-1] << '\n';
        if(abs(fibo[it] - input) < abs(fibo[it-1] - input))
        {
            cout << fibo[it] << endl;
        }
        else if (abs(fibo[it] - input) == abs(fibo[it-1] - input))
        {
            cout << fibo[it] << endl;
        }
        else cout << fibo[it-1] << endl;
    }
}