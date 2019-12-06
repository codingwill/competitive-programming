#include <bits/stdc++.h>

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

//JUST TO MAKE MY LIFE EASIER
#define for(i, n, k) for(int i = (int)(k); i < n; i++)

//TIPE DATA BENTUKAN

int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    k = k-1;
    string letter;
    cin >> letter;
    sort(letter, letter+(n*l));
    string word[n];
    int lexiValue = INT32_MAX;
    int minimIndex;
    for (i, (n*l)-l, k)
    {
        int subValue = 0;
        for (j, i+l, i)
        {
            subValue += letter[j]; 
        }
        if (subValue == 0)
        {
            minimIndex = i;
            break;
        }
        if (lexiValue > subValue)
        {
            minimIndex = i;
        }
        lexiValue = min(subValue, lexiValue);
    }
    for (i, n, 0)
    {
        if (i != k)
        {
            word[n]
        
        }
    }
}