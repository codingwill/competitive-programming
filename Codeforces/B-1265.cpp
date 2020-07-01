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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int l = 0, r = n-1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        vector<int> ans;
        //ans.push_back(1);
        priority_queue<int, vector<int>, greater<int>> pq;
        int start = n;
        pq.push(n+1);
        while (true)
        {
            if (a[l] > a[r])
            {
                if (r-l+1 < pq.top() || n == r-l+1)
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(0);
                }
                pq.push(a[l]);
                l++;
                
            }
            else
            {
                if (r-l+1 < pq.top() || n == r-l+1)
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(0);
                }
                pq.push(a[r]);
                r--;
            }
            if (l - r == 1)
            {
                break;
            }
        }
        for (int i = n-1; i >= 0; --i)
        {
            cout << ans[i];
        }
        cout << '\n';
        ans.clear();
        a.clear();
    }
}