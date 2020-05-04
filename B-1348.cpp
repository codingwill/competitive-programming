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
        int n, k;
        cin >> n >> k;
        vector<ll> a;
        vector<ll> v;
        set<ll> s;
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            ll input;
            cin >> input;
            a.push_back(input);
            if (s.find(input) == s.end()) v.push_back(input);
            s.insert(input);
        }
        sort(v.begin(), v.end());
        if (s.size() > k)
        {
            cout << "-1" << '\n';
            continue;
        }
        else if (s.size() < k)
        {
            for (int i = 1; i <= n; i++)
            {
                if (v.size() == k) break;
                if (s.find(i) == s.end()) v.push_back(i);
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                ans.push_back(v[j]);
            }
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size()-1) cout << ' ';
        }
        cout << '\n';
        a.clear();
        ans.clear();
        s.clear();
        v.clear();
    }
}

/*

1 4 4 4 4


4 3 4 2
k = 4
4 3 [2] [1] 4 [3] 2 << benar
4 3 [1] [1] 4 [3] [1] [1] [4] [1] [3] 2 << salah
4 3 [5] [6] 4 [3] [5] [6] [4] 2 << salah
4 3 [5] [2] 4 [3] [5] 2

2 7 9 9 2
k = 3
2 7 9 [2] [7] 9


2 4 4 3
[4] [3] 2 [1] 4 [3] [2] [1] 4 

6 8 9 6 
k = 4
6 [7] 8 9 6 

7 6 8 7 5 2 4
k = 4
7 6 [5] [4] [7] [6] [5] [4] [7] 8 7 5 2 4 << salah
7 6 [1] [2] [7] [6] [1] 8 7  5 2 4
7 6 [1] [1] [7] 8 7 5 2 4

2 4 3
k=2
2 5 3 4

2 3 5
k=2
2 6 3 5

2 3 6
k=2
2 7 3 6

2 3 5 6
k = 2
2 9 3 8 4 7 4 5 6

2 7 8 4 9 4
k = 2
-1

2 7 7 2 2 7
k = 2
2 7 2 7 2 7 2 7

>>if neighbors are equal, then insert<<


2 7 7 2 2 7 
k = 3
m = 8
2 7 [2] 7 2 [7] 2 7 
m = 11
2 7 [1] [2] 7 [1] 2 [7] [1] 2 7 

6 3 5 7
k = 3
6 3 [2] [6] [3] 5 7

4 3 4 2
k = 4
4 [1] 3 4 [4] [1] [3] [4] [4] [1] [1] [6] [4] [1] [1] [6] 2 << algoritma salah
k = 4


*/