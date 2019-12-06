#include <bits/stdc++.h>

// MACRO ORANG GILA
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

int main()
{
    int n = 100000;
    stack<int> piring;
    for (int i = n; i > 0; i--)
    {
        piring.push(i);
    }
    for (int i = n; i > 0; i--)
    {
        cout << piring.top() << endl;
        piring.pop();
    }
}