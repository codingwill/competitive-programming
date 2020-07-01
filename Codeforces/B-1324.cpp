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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            v.push_back(input);
        }
        if (n == 2) 
        {
            puts("NO");
            continue;
        }
        bool can = false;
        int p1 = 0, p2 = 2; //pointer kiri, pointer kanan
        //palindrom ganjil
        //[1] 3 [2] 4 5 [1]
        for (int i = 0; i < n-2; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (v[i] == v[j]) can = true;
            }
        }
        int kiriDalam = -1, kiriLuar = n, kananDalam = n, kananLuar = -1;
        //palindrom genap
        for (int i = 0; i < n-2; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (v[i] == v[j])
                {
                    kiriDalam = max(i, kiriDalam);
                    kiriLuar = min(i, kiriLuar);
                    kananLuar = max(j, kananLuar);
                    kananDalam = min(j, kananDalam);
                }
            }
        }
        if (kiriDalam > kiriLuar && kananDalam < kananLuar) can = true;
        // [1] 3 5 [2] 3 9 [2] 7 [1]
        //1 3 5 2 3 9 2 7 1
        if (can) puts("YES");
        else puts("NO");
    }
    return 0;
}
