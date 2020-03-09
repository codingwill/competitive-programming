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

using ll = long long int;

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
        vector<tuple<int, int, int>> brightness;
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            brightness.push_back(make_tuple(input, 0, 0));
        }
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            get<1>(brightness[i]) = input;
            get<2>(brightness[i]) = input + get<0>(brightness[i]);
        }
        sort(brightness.begin(), brightness.end(), tupleSort);
        for (int i = 0; i < n; i++)
        {
            cout << get<2>(brightness[i]) << " " << get<1>(brightness[i]) << " " << get<0>(brightness[i]) << '\n';
            
        }
        
    }
    

}