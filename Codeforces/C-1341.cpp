#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool sortByNum(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

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
        vector<pair<int, int>> p; //nomor, posisi
        map<int, bool> used; //posisi terpakai or not
        bool can = true;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            p.push_back(make_pair(input, i+1));
        }
        sort(p.begin(), p.end(), sortByNum);
        for (int i = 0; i < n; i++)
        {
            used[p[i].second] = true;
            if (i > 0)
            {
                if (p[i-1].second == n) continue;
                if (used[p[i-1].second + 1]) continue;
                if (p[i].second - p[i-1].second != 1)
                {
                    can = false;
                    break;
                }
            }
            
        }
        can ? cout << "Yes" : cout << "No";
        cout << '\n';
        p.clear();
    }
}
/*
1
10
9 10 8 6 7 2 3 4 5 1
No
====
Should be "Yes"

*/