#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool allCaps = true;
    string input;
    cin >> input;
    for (int i = 1; i < input.length(); i++)
    {
        if (input[i] > (int)'Z')
        {
            allCaps = false;
        }
    }
    if (allCaps)
    {
        if (input[0] >= 'a') input[0] = toupper(input[0]);
        else input[0] = tolower(input[0]);
        for (int i = 1; i < input.length(); i++)
        {
            input[i] = tolower(input[i]);
        }
    }
    cout << input << '\n';
    return 0;
}