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
    int n;
    cin >> n;
    string ans[n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        bool sama = true;
        string input;
        string s[2];
        int p = 0; 
        getline(cin, input);
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] != ' ')
            {
                if (input[j] == 'A' || input[j] == 'I' || input[j] == 'U' || input[j] == 'E' ||input[j] == 'O') s[p] += "V";
                else s[p] += "K";
            }
            else
            {
                if (k < 1)
                {
                    p++;
                    k++;
                }
                else
                {
                    s[p] += " ";
                }
                
            }
        }
        for (int j = 0; j < max(s[0].length(), s[i].length()); j++)
        {
            if (s[0].length() != s[1].length())
            {
                sama = false;
                break;
            }
            if (s[0][j] != s[1][j])
            {
                sama = false;
            }
        }
        sama ? ans[i] = "SAMA\n" : ans[i] = "BEDA\n";
    }
    for (string n : ans) cout << n;
}