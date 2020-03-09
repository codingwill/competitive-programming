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
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a, b, x, y, c, aCopy,bCopy;
    for (int i = 0; i < A; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
        aCopy.push_back(input);
    }
    for (int i = 0; i < B; i++)
    {
        int input;
        cin >> input;
        b.push_back(input);
        bCopy.push_back(input);
    }
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        x.push_back(input);
        cin >> input;
        y.push_back(input);
        cin >> input;
        c.push_back(input);
        
    }
    
    //tanpa tiket
    sort(aCopy.begin(), aCopy.end());
    sort(bCopy.begin(), bCopy.end());
    int minim = aCopy[0] + bCopy[0];

    //dengan tiket
    for (int i = 0; i < M; i++)
    {
        minim = min(minim, a[x[i]-1] + b[y[i]-1] - c[i]);
    }

    cout << minim << '\n';
    return 0;
}
