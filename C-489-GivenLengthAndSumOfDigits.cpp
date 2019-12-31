#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool can(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}

bool highFirst(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, s;
    cin >> m >> s;

    string minim, maxim;
    int sum = s;
    bool possible = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if ((i > 0 || j > 0 || (m == 1 && j == 0)) && can(m - i - 1, sum - j))
            {
                possible = true;
                minim += char('0' + j);
                sum -= j;
                break;
            }
        }
        if (m > 1 && s == 0) break;
    }
    
    sum = s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if ((i > 0 || j > 0 || (m == 1 && j == 0)) && can(m - i - 1, sum - j))
            {
                possible = true;
                maxim += char('0' + j);
                sum -= j;
                break;
            }
        }
        if (m > 1 && s == 0) break;
    }

    if (!possible)
    {
        cout << "-1 -1\n";
        return 0;
    }
    cout << minim;
    //sort(minim.begin(), minim.end(), highFirst);
    cout << " " << maxim << '\n';
    return 0;
}