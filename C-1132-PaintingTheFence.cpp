#include <bits/stdc++.h>
#include <chrono> 

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
    int a = 1, b = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
    }
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 50000000; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            //a--;
            //b++;
            //b--;
            a++;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cout << a << '\n';
    cout << "Waktu komputasi: " << (float)duration.count()/1e3 << " ms" << endl;
    return 0;
}