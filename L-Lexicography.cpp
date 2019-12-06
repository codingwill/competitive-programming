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
    int letterPoint = 0;
    for (i, n, 0)
    {
        word[i].insert(letter.substr(i*3, 3));
    }
    int lexiCount = 0;
    for (i, word[k].length()-1, 0)
    {
        lexiCount += abs(word[k][i] - word[k][i+1]);
    }

    if (lexiCount == 0 || k == 0)
    {
        for (i, n, 0)
        {
            cout << word[i] << "\n";
        }
        return 0;
    }
    int tidakSama = 0;
    for (i, n, 0)
    {
        if (word[k][i] != word[k][i])
        {
            tidakSama++;
        }
    }
}