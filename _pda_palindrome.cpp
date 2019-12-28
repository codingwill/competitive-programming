#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    stack<char> pal;
    s1 = "wiliw";
    s2 = "10101010000";
    for (int i = 0; i < s1.length(); i++)
    {
        if (i < s1.length()/2)
        {
            pal.push(s1[i]);
        }
        else
        {
            if (pal.top() == s1[i]) pal.pop();
        }
    }
    if (pal.empty()) cout << "Palindrome!" << endl;
    else cout << "Bukan Palindrome!" << endl;
}