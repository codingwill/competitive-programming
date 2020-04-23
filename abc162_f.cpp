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
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(make_pair(input, i));
    }
    sort(a, a+n);
    int count = 0;
    int sum = 0;
    for (int i = n-1; i > 0; i--)
    {
        if (i == n-1) sum += a[i].first;
        if (a[i].)
        count++;
        if (count >= n/2)
        {
            break;
        }
    }
    for (int n : a) cout << n << ' ';
    cout << endl;
    cout << sum << '\n';
    return 0;
}
/*
5
-1000 -100 -10 0 10
-2 -1 0 130 132 250 251

27
18 -28 18 28 -45 90 -45 23 -53 60 28 -74 -71 35 -26 -62 49 -77 57 24 -70 -93 69 -99 59 57 -49
-99 -93 -77 -74 -71 -70 -62 -53 -49 -45 -45 -28 -26 18 18 23 24 28 28 35 49 57 57 59 60 69 90
-4
90 + 28 + 18 + 23 + 60 + 35 + 49 + 57 + 69 + 59 + 

90 + 60 + 57 + 49 + 28 + 24 + 18 + -26 + -45 + -49 + -62 + -71 + -77
*/