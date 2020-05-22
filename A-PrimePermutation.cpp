#include <bits/stdc++.h>

//AUTHOR'S NAME
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<bool> prime(1005, true);
    map<char, int> m;
    pair<char, int> mostChar;
    vector<int> listPrime;
    int len = s.length();
    //sieve of eratosthenes
    prime[1] = false;
    for (int i = 1; i < prime.size(); i++)
    {
        if (i % 2 == 0) prime[i] = false; 
    }
    for (int i = 1; i*i < prime.size(); i++)
    {
        if (prime[i])
        {
            for (int j = 2*i; j < prime.size(); j += i)
            {
                prime[j] = false;
            }
        }
    }

    int same = 0;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
        if (i == 0)
        {
            mostChar.first = s[i];
            mostChar.second = m[s[i]];
        }
        else
        {
            if (m[s[i]] > mostChar.second)
            {
                mostChar.first = s[i];
                mostChar.second = m[s[i]];
            }
        }
        if (prime[i] || prime[(i+1)/2])
        {
            same++;
        }
    }
    string ans = "";
    int x = 0;
    if (mostChar.second < same)
    {
        cout << "NO" << '\n';
        return 0;
    }
    else
    {
        cout << "YES" << '\n';
        for (int i = 0; i < same; i++)
        {
            s.erase(s.find(mostChar.first), 1);
        }
        for (int i = 0; i < len; i++)
        {
            if (prime[i+1] || prime[(i+2)/2])
            {
                ans += mostChar.first;
            }
            else
            {
                ans += s[x];
                x++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}