#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string up_dvorak = "~!@#$%^&*(){}\"<>PYFGCRL?+|AOEUIDHTNS_:QJKXBMWVZ";
    string up_qwerty = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    string lo_dvorak = "`1234567890[]',.pyfgcrl/=\\aoeuidhtns-;qjkxbmwvz";
    string lo_qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string input;
    getline(cin, input);
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < up_dvorak.length(); j++)
        {
            if (input[i] == up_dvorak[j])
            {
                output += up_qwerty[j];
                break;
            }
            else if (input[i] == lo_dvorak[j])
            {
                output += lo_qwerty[j];
                break;
            }
            else if (input[i] == ' ')
            {
                output += ' ';
                break;
            }
        }
    }
    cout << output << '\n';
    return 0;
}