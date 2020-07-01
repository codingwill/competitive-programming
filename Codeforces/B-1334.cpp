#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

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
    vector<int> ans;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        sort(a.begin(), a.end(), besarDulu);
        ll sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if ((double)sum / (i+1) >= x)
            {
                count++;
            }
            else break;
        }
        ans.push_back(count);
    }
    for (int n : ans) cout << n << '\n';
    return 0;
}
