#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;


using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    
    while (k--)
    {
        bool bisa = false;
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int count = 0;
        vector<int> swapPos;
        for (int i = 0; i < n; i++)
        {
            string x, y;
            x = a;
            y = b;
            if (x[i] == y[i])
            {
                count++;
            }
            else
            {
                swapPos.push_back(i);
            }
            //sort(x.begin(), x.end());
            //sort(y.begin(), y.end());
            //swap(x[i], y[i]);
            if (x == y)
            {
                bisa = true;
                break;
            }
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                string x, y;
                x = a;
                y = b;
                swap(x[swapPos[i]], y[swapPos[j]]);
                if (x == y) bisa = true;
            }
        }
        if (bisa) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
/*
souse
houhe

eossu
ehhou
*/