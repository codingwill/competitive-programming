#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

//WRONG SOLUTION
 
Willy Indrayana Komara;

using ll = long long;

bool decrOrder(const int &a, const int &b)
{
    return a > b;
}
bool decrOrderPair(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ans(n);
    vector<pair<int, int>> sortedFreq(n), range(q);
    map<int, int> freq;
    vector<int> dp(200005, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ans = a;
    sort(a.begin(), a.end(), decrOrder);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        range.push_back(make_pair(l, r));
        if (freq[l] == 0) sortedFreq.push_back(make_pair(l, 0));
        if (freq[r] == 0) sortedFreq.push_back(make_pair(r, 0)); 
        freq[l]++;
        freq[r]++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < sortedFreq.size(); i++)
    {
        sortedFreq[i].second = freq[sortedFreq[i].first];
    }
    sort(sortedFreq.begin(), sortedFreq.end(), decrOrderPair);
    for (int i = 0; i < n; i++)
    {
        cout << sortedFreq[i].first << ' ';
        ans[sortedFreq[i].first] = a[i];
        if (i == 0) dp[i] = a[i];
        else dp[i] += dp[i-1] + a[i];
    }
    cout << endl;
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (range[i].first == 1 ? dp[range[i].second] : dp[range[i].second] - dp[range[i].first-1]);
    }
    
    cout << sum << '\n';
}