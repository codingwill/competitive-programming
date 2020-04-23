#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[10][10];
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    bool possible[10][10];
    memset(possible, 0, sizeof(possible));
    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        for (int j = 0; j < 10; j++)
        {
            if (j > 0)
                if (abs(a[i][j-1] - a[i][j]) <= 1) possible[i][j] = true;
            if (i > 0)
                if (abs(a[i-1][j] - a[i][j]) <= 1) possible[i][j] = true;
            if (j < 9)
                if (abs(a[i][j+1] - a[i][j]) <= 1) possible[i][j] = true;
            if (i < 9)
                if (abs(a[i+1][j] - a[i][j]) <= 1) possible[i][j] = true;
        }
    }

    //Shortest Path
    for (int i = 0; i < 10; i++)
    {
        int j = 0;
        if (!possible[i][j])
        {
            continue;      
        }
        while (j < 9)
        {
            
        }
    }
    /*
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    */
}