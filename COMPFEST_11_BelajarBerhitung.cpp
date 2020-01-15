#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool kecBes(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) return a.second < a.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll sum = 0;
    vector<pair<int, int>> anak;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        anak.push_back(make_pair(l, r));
    }
    sort(anak.begin(), anak.end(), kecBes);
    int index = 0;
    int prevMin = anak[0].first;
    for (int i = 1; i < n; i++)
    {
        if (anak[i].second)

    }
    cout << sum << '\n';
    
}