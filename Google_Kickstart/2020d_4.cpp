#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int myMod(int a, int b)
{
    if (a % b == 0) return 3;
    return a % b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int num = t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<ll> d;
        int s, k;
        for (int i = 0; i < n-1; ++i)
        {
            ll input;
            cin >> input;
            d.push_back(input);
        }
        // two pointers for test set 1
        vector<int> ans;
        for (int i = 0; i < q; ++i)
        {
            cin >> s >> k;
            int p = 1;
            int l, r;
            if (s == 1)
            {
                ans.push_back(k);
            }
            else if (s == n)
            {
                ans.push_back(n-(k-1));
            }
            else
            {
                l = s - 2;
                r = s - 1;
                while (p < k)
                {
                    if (l < 0 || r >= n-1)
                    {
                        if (l < 0)
                        {
                            s = r + 1;
                            ++r;
                        }
                        else
                        {
                            s = l;
                            --l;
                        }
                    }
                    else
                    {
                        //cout << d[l] << ' ' << d[r] << '\n';
                        if (d[l] < d[r])
                        {
                            s = l;
                            --l;
                        }
                        else
                        {  
                            s = r + 1;
                            ++r;
                        }
                    }
                    //cout << s + 1 << ' ';
                    ++p;
                }
                if (k == 1) ans.push_back(s);
                else ans.push_back(s + 1);
            }
        }
        cout << "Case #" << num-t << ": ";
        for (int n : ans) cout << n << ' ';
        cout << '\n';
    }
}