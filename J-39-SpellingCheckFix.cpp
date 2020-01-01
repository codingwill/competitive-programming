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
    int i = 0, j = 0;
    int left = 0, right = 0;
    while (s1[i] == s2[j])
    {
        left++;
        i++;
        j++;
    }
    int index = i+1;
    i++;
    while (s1[i] == s2[j])
    {
        right++;
        i++;
        j++;
    }
    if (left + right - 1 < s2.length())
    {
        cout << "0" << '\n';
        return 0;
    }
    if (right > 0 && left > 0)
    {
        cout << "1" << '\n';
        cout << index << '\n';
    }
    else
    {
        cout << s1.length() << '\n';
        for (int i = 0; i < s1.length()-1; i++)
        {
            cout << i+1 << " ";
        }
        cout << s1.length()-1 << '\n';
    }
    
    return 0;
}