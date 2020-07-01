#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool besarDulu(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
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
        vector<pair<int, int>> a; //first = skillSet, second = counter
        vector<int> skillSet;
        map<int, int> counter;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            counter[input]++;
            if (counter[input] == 1) skillSet.push_back(input);
        }
        for (int i = 0; i < skillSet.size(); i++)
        {
            a.push_back(make_pair(skillSet[i], counter[skillSet[i]]));
        }
        sort(a.begin(), a.end(), besarDulu);
        int ans;
        if (a[0].second > a.size())
        {
            ans = a.size();
        }
        else if (a[0].second == a.size())
        {
            ans = a[0].second - 1;
        }
        else
        {
            ans = a[0].second;
        }
        
        cout << ans << '\n';

    }
    return 0;
}
/*
4 2 4 1 4 3 4

WRONG TEST
1
4
1 1 1 3
[1]

1
5
2 1 5 4 3
[0]
*/