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
    int t;
    cin >> t;
    while (t--)
    {
        int n, a , b;
        cin >> n >> a >> b;
        string s = "";
        char kar = 'a';
        set<char> charList;
        map<char, int> charCount;
        for (int i = 0; i < n - a + 1; i++)
        {
            //int count = 0;
            if (kar > 'z') kar = 'a';
            if (i == 0)
            {
                for (int j = 0; j < b; j++)
                {
                    s += kar;
                    charCount[kar]++;
                    charList.insert(kar);
                    kar++;
                }
                for (int j = i+b; j < i+a; j++)
                {
                    charList.insert(s[s.length()-1]);
                    charCount[s[s.length()-1]]++;
                    s += s[s.length()-1];
                }
            }
            else
            {
                charCount[s[i-1]]--;
                if (charCount[s[i-1]] == 0)
                {
                    charList.erase(s[i-1]);
                }
                if (charList.size() < b)
                {
                    //cout << 't' << endl;
                    s += kar;
                    charCount[kar]++;
                    charList.insert(kar);
                    kar++;
                }
                else
                {
                    charCount[s[s.length()-1]]++;
                    s += s[s.length()-1];
                }
                
            }
            
        }
        cout << s << '\n';
    }
    return 0;
}
/*
abcccdeeef
*/