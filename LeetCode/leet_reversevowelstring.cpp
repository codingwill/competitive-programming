#include <bits/stdc++.h>

using namespace std;

class Solution 
{
private:
    string vowel = "";
public:
    string reverseVowels(string s) 
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
            {
                vowel += s[i];
            }
            else if (s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O')
            {
                vowel += s[i];
            }
        }
        reverse(vowel.begin(), vowel.end());
        int j = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o')
            {
                s[i] = vowel[j];
                ++j;
            }
            else if (s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O')
            {
                vowel += s[i];
            }
        }
        return s;
    }
};