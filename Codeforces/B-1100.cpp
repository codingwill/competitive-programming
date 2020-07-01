#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, int> k;
    vector<int> a;
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for (int i = 0; i < m; i++)
    {
        k[a[i]]++;
        if (k.size() == n)
        {
            cout << "1";
            for (int j = 1; j <= n; j++)
            {
                k[j]--;
                if (k[j] == 0) k.erase(j);
            }
        }
        else
        {
            cout << '0';
        }
    }
    
}