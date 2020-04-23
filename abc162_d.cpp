#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int r[4001], g[4001], b[4001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    cin >> n;
    //count R, G, B individually and assign to an array
    string s;
    cin >> s;
    if (s[0] == 'R') r[0] += 1;
    if (s[0] == 'G') g[0] += 1;
    if (s[0] == 'B') b[0] += 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'R') r[i] += r[i-1] + 1;
        else r[i] = r[i-1];
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'G') g[i] += g[i-1] + 1;
        else g[i] = g[i-1];
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'B') b[i] += b[i-1] + 1;
        else b[i] = b[i-1];
    }

    //count sum of combination starting with R that satisfy the conditions
    ll sum = 0;
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'R')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'G')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (b[n-1] - b[j + abs(i-j)] > 0)
                        {
                            sum += (b[n-1] - b[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (b[j + abs(i-j) - 1] - b[j] > 0)
                            {
                                sum += (b[j + abs(i-j) - 1] - b[j]);
                            }
                        }
                        else
                        {
                            if (b[n-1] - b[j] > 0)
                            {
                                sum += b[n-1] - b[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                        
                }
            }
        }
    }
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'R')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'B')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (g[n-1] - g[j + abs(i-j)] > 0)
                        {
                            sum += (g[n-1] - g[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (g[j + abs(i-j) - 1] - g[j] > 0)
                            {
                                sum += (g[j + abs(i-j) - 1] - g[j]);
                            }
                        }
                        else
                        {
                            if (g[n-1] - g[j] > 0)
                            {
                                sum += g[n-1] - g[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'G')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'R')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (b[n-1] - b[j + abs(i-j)] > 0)
                        {
                            sum += (b[n-1] - b[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (b[j + abs(i-j) - 1] - b[j] > 0)
                            {
                                sum += (b[j + abs(i-j) - 1] - b[j]);
                            }
                        }
                        else
                        {
                            if (b[n-1] - b[j] > 0)
                            {
                                sum += b[n-1] - b[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'G')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'B')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (r[n-1] - r[j + abs(i-j)] > 0)
                        {
                            sum += (r[n-1] - r[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (r[j + abs(i-j) - 1] - r[j] > 0)
                            {
                                sum += (r[j + abs(i-j) - 1] - r[j]);
                            }
                        }
                        else
                        {
                            if (r[n-1] - r[j] > 0)
                            {
                                sum += r[n-1] - r[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'B')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'R')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (g[n-1] - g[j + abs(i-j)] > 0)
                        {
                            sum += (g[n-1] - g[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (g[j + abs(i-j) - 1] - g[j] > 0)
                            {
                                sum += (g[j + abs(i-j) - 1] - g[j]);
                            }
                        }
                        else
                        {
                            if (g[n-1] - g[j] > 0)
                            {
                                sum += g[n-1] - g[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    for  (int i = 0; i < n-3; i++)
    {
        if (s[i] == 'B')
        {
            for (int j = i+1; j < n-1; j++)
            {
                if (s[j] == 'G')
                {
                    if (j + abs(i-j) < n)
                    {
                        if (r[n-1] - r[j + abs(i-j)] > 0)
                        {
                            sum += (r[n-1] - r[j + abs(i-j)]);
                        }
                        //cerr << i << " " << j << endl;
                    }
                    if (abs(i-j) > 1)
                    {
                        if (j + abs(i-j) < n)
                        {
                            if (r[j + abs(i-j) - 1] - r[j] > 0)
                            {
                                sum += (r[j + abs(i-j) - 1] - r[j]);
                            }
                        }
                        else
                        {
                            if (r[n-1] - r[j] > 0)
                            {
                                sum += r[n-1] - r[j];
                                //cerr << "test" << endl;
                            }
                        }
                        
                    }
                }
            }
        }
    }
    //cout << b[n-1]  << endl;
    cout << sum << '\n';

    return 0;
}

/*
WRONG TEST CASE:

7
GRRBGBR
1 (WA)
4 (AC)

GR B
GR   B
 R BG
   BG R

broken mouse :((

*/