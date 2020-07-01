#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

bool pairSort(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

using ll = long long int;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int guru[n];
    int murid[n];
	vector<int> diff;
    for(int i = 0; i < n; i++)
		cin >> guru[i];
	for(int i = 0; i < n; i++)
		cin >> murid[i];
	ll count = 0;
	for (int i = 0; i < n; i++)
    {
        diff.push_back(guru[i] - murid[i]);
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < n; i++)
    {
        int a = diff[i];
        int b = -a;
        int c = upper_bound(diff.begin(), diff.end(), b) - diff.begin();
        c = n - c;
        if (a > 0) c--;
        count += c;
    }
	cout << count/2 << '\n';
}