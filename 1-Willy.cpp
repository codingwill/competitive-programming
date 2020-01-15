

#include <bits/stdc++.h>


//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono; 

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

using ll = long long int;

int main()
{
    int t;
    scanf("%d", &t);
    auto start = high_resolution_clock::now(); 
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }            
        ll dp[100005];
        ll count = 0;
        for (int i = 0; i < n-1; i++)
        {
            ll minim = INT32_MAX;
            dp[i+1] = a[i] & a[i+1];
            minim = min(minim, min(a[i], a[i+1]));
            if (minim > dp[i+1]) count++;
            for (int j = i+2; j < n; j++)
            {
                dp[j] = dp[j-1] & a[j];
                minim = min(minim, a[j]);
                if (dp[j] == 0)
                {
                    count += (n - j);
                    break;
                }
                if (dp[j] > minim) 
                {
                    count++;
                }
            }
        }
        printf("%lld\n", count);
    }
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "durasi adalah: " << duration.count()/1000 << "ms." << endl;
    return 0;
}
/*
0001
0111
0001
*/