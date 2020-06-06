#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/05
*/
using namespace std;
using ll = long long int;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    map<string, string> daftar;
    for (int i = 0; i < n; ++i)
    {
        string nama, nomor;
        cin >> nama >> nomor;
        daftar[nama] = nomor;
    }
    for (int i = 0; i < q; ++i)
    {
        string nama;
        cin >> nama;
        if (daftar.find(nama) != daftar.end())
        {
            cout << daftar[nama] << '\n';
        }
        else
        {
            cout << "NIHIL" << '\n';
        }
    }
}