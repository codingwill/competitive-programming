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

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> index;
    for (int i = 0; i < s1.length(); i++)
    {
        string s1Copy;
        if (i == 0)
            s1Copy = s1.substr(i+1, s1.length()-(i+1));
        else
        {
            s1Copy = s1.substr(0, i) + s1.substr(i+1, s1.length()-(i+1));
            //cout << s1Copy << endl;
        }
        if (s1Copy == s2)
        {
            index.push_back(i+1);
        }
    }
    if (index.empty())
    {
        cout << "0" << '\n';
        return 0;
    }
    cout << index.size() << '\n';
    for (int i = 0; i < index.size()-1; i++)
    {
        cout << index[i] << ' ';
    }
    cout << index[index.size()-1] << '\n';
    return 0;
}