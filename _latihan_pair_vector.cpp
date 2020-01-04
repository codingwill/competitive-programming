#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool bigSorting(string a, string b)
{
    if (a.length() > b.length()) return true;
    if (a.length() == b.length()) return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n, bigSorting);
    cout << "setelah sort: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }

}