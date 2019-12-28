#include <bits/stdc++.h>
#include <chrono>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll a, m;
        cin >> a >> m;
        auto start = high_resolution_clock::now(); 
        ll nPossMax = m / a;
        ll nPossMin = m / (a+1);
        vector<ll> n;
        for (ll i = nPossMin; i <= nPossMax; i++)
        {
            if (m - a*i == 0) continue;
            if (i % (m - a*i) == 0) n.push_back(i);
        }
        if (n.size() == 0)
        {
            cout << "0\n\n";
            continue;
        }
        cout << n.size() << '\n';
        for (int i = 0; i < n.size()-1; i++)
        {
            cout << n[i] << ' ';
        }
        cout << n[n.size()-1] << '\n';
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start); 
        //cout << "Time taken by function: " << duration.count()/1000 << " ms" << endl; 
    }
    return 0;
}