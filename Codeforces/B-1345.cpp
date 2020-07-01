#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<long long> arr(200005);
    vector<long long> a(200005);
    arr[1] = 2;
    a[1] = 2;
    for (int i = 2; i < 200005; i++)
    {
        arr[i] = arr[i-1] + 3;
    }
    for (int i = 2; i < 200005; i++)
    {
        a[i] = a[i-1] + arr[i];
    }
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        vector<long long>::iterator it = lower_bound(a.begin(), a.end(), n);
        if (n < 2)
        {
            cout << "0" << '\n';
            continue;
        }
        if (n < a[(it-a.begin())] ) it--;
        while (true)
        {   
            if (n < 2) break;
            ans++;
            n = n - a[it-a.begin()]; 
            it = lower_bound(a.begin(), a.end(), n);
            if (n < a[(it-a.begin())]) it--;
        }
        cout << ans << '\n';
    }
}

/*
h = 1
2
p = 2

h = 2
5
p = 7

h = 3
8
p = 15
*/