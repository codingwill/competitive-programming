#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

using ll = long long int;

Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p, k;
        cin >> n >> p >> k;
        vector<ll> a;
        for (ll i = 0; i < n; i++)
        {
            ll input;
            cin >> input;
            a.push_back(input);
        }
        ll countItem = 0;
        sort(a.begin(), a.end());
        /*
        for (int i = 1; i < n; i++)
        {
            ll sumPrice = a[i];
            ll countTemp = 2;
            ll j = i-2;
            if (sumPrice > p)
            {
                countTemp = 0;
                continue;
            }
            while (true)
            {
                if (sumPrice > p) break;
                if (j >= 0)
                {
                    sumPrice += a[j];
                    countTemp++;
                    j--;
                }
                else
                {
                    break;
                }
                
            }
            countItem = max(countItem, countTemp);
        }
        */

        
        for (ll i = 0; i < n; i++)
        {
            ll sumPrice = 0;
            ll countTemp = 0;
            ll j = i;
            while (sumPrice <= p && j < n && a[j] <= p)
            {
                sumPrice += a[j];
                countTemp++;
                j++;
            }
            j--;
            if (sumPrice - a[j-1] > p)
            {
                countTemp--;
            }
            countItem = max(countItem, countTemp);
        }
        
        cout << countItem << '\n';
    }
    return 0;
}
/*
5 11 2
2 4 3 5 7
7 5 4 3 2
(7, 5) + 4 = 11 -> 3 items

2 3 4 5 7
(4, 3) + 2 + 5 = 11 -> 4 items
2 3 4 5 7
(5, 4) + 3 + 2 = 10 -> 4 items
*/