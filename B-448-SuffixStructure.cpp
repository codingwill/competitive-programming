#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool highFirst(const int &a, const int &b)
{
    return a > b;
}

int kar1[26], kar2[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2, s1Copy, s2Copy;
    cin >> s1 >> s2;
    int found = s1.find(s2);
    bool automaton = true, array = true, possible = true;
    int pnt = 0;
    
    if (s1.length() == s2.length()) 
    {
        automaton = false;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        kar1[s1[i]-'a']++;
    }
    for (int i = 0; i < s2.length(); i++)
    {
        kar2[s2[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        //cout << kar1[i] << " " << kar2[i] << endl;
        if (kar1[i] < kar2[i]) 
        {
            possible = false;
        }
    }
    
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[pnt])
        {
            pnt++;
        }
        if (pnt == s2.length())
        {
            array = false;
            break;
        }
    }
    if (!possible)
    {
        cout << "need tree\n";
    }
    else
    {
        if (automaton && array) cout << "both\n";
        else if (automaton && !array) cout << "automaton\n";
        else if (!automaton && array) cout << "array\n";
    }
    
}