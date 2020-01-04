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
    vector<pair<string, int>> dataNilai;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string nama;
        int nilai;
        cin >> nama >> nilai;
        dataNilai.push_back(make_pair(nama, nilai));
    }
    for (int i = 0; i < n; i++)
    {
        cout << dataNilai[i].first << ": " << dataNilai[i].second << endl;
    }
    return 0;
}