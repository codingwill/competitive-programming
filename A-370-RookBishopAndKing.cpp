#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

void king(int a, int b, int c, int d)
{
    int count = 0;
    if (a > c && b < d)
    {
        while (!(a == c || b == d))
        {
            a--;
            b++;
            count++;
        }
    }
    else if (a < c && b < d)
    {
        while (!(a == c || b == d))
        {
            a++;
            b++;
            count++;
        }
    }
    else if (a < c && b > d)
    {
        while (!(a == c || b == d))
        {
            a++;
            b--;
            count++;
            //cout << a << '\n';
        }
    }
    else if (a > c && b > d)
    {
        while (!(a == c || b == d))
        {
            a--;
            b--;
            count++;
        }
    }
    if (a == c && b != d)
    {
        count += abs(b-d);
    }
    else if (b == d && a != c)
    {
        count += abs(a-c);
    }
    cout << count << '\n';
}

void bishop(int a, int b, int c, int d)
{
    if ((a+b) % 2 != (c+d) % 2)
    {
        cout << "0" << ' ';
    }
    else if (abs(a-c) == abs(b-d))
    {
        cout << "1" << ' ';
    }
    else
    {
        cout << "2" << ' ';
    }
    
}

void rook(int a, int b, int c, int d)
{
    if (a == c || b == d)
    {
        cout << "1" << ' ';
    }
    else if (a != c && b != d)
    {
        cout << "2" << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    rook(r1, c1, r2, c2);
    bishop(r1, c1, r2, c2);
    king(r1, c1, r2, c2);
    return 0;
}