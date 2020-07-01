#include <bits/stdc++.h>
#include <chrono>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string sub;
    if (s.length() < 4)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < s.length()-3; i++)
    {
        sub = s.substr(i, 2);
        if (sub == "AB")
        {
            for (int j = i+2; j < s.length()-1; j++)
            {
                sub = s.substr(j, 2);
                if (sub == "BA")
                {
                    cout << "YES" << '\n';
                    return 0;
                }
            }
            break;
        }
    }
    for (int i = 0; i < s.length()-3; i++)
    {
        sub = s.substr(i, 2);
        if (sub == "BA")
        {
            for (int j = i+2; j < s.length()-1; j++)
            {
                sub = s.substr(j, 2);
                if (sub == "AB")
                {
                    cout << "YES" << '\n';
                    return 0;
                }
            }
            break;
        }
    }
    cout << "NO" << '\n';
    return 0;
}