#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

bool kurungComp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int z = 1;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> kurungBuka;
        //vector<pair<int, int>> kurung; //kurung buka, kruung tutup
        map<char, int> key;
        key['N'] = 0; key['W'] = 0; key['E'] = 0; key['S'] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                kurungBuka.push(i);
            }
            else if(s[i] == ')')
            {
                //kurung.push_back(make_pair(kurungBuka.top(), i));
                
                string func = s.substr(kurungBuka.top() + 1, i - kurungBuka.top() - 1);
                string temp = "";
                for (int k = 0; k < s[kurungBuka.top()-1] - '0'; k++)
                {
                    temp += func;
                }
                s.erase(kurungBuka.top()-1, i - kurungBuka.top() + 2);
                //cout << temp;
                s.insert(kurungBuka.top()-1, temp);
                //cout << s << endl;
                i = kurungBuka.top()-1 + temp.size()-1;
                kurungBuka.pop();
            }
        }
        //cout << kurungBuka.max_size() << endl;
        int x = 1, y = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'N') key['N']++;
            if (s[i] == 'S') key['S']++;
            if (s[i] == 'E') key['E']++;
            if (s[i] == 'W') key['W']++;
        }
        x += key['S'] - key['N'];
        y += key['E'] - key['W'];

        x = x % 1000000000;
        y = y % 1000000000;
        if (x < 0) x = 1000000000 + x;
        if (y < 0) y = 1000000000 + y;
        if (x == 0) x = 1000000000;
        if (y == 0) y = 1000000000;
        //cout << s << endl;
        cout << "Case #" << z  << ": " <<  y << ' ' << x << '\n';
        z++;
    }
}
/*
2(3(NW)2(W2(EE)W))
NWNWNWWEEEEWWEEEEWNWNWNWWEEEEWWEEEEW
NWNWNWWEEEEWWEEEEWNWNWNWWEEEEWWEEEEW
NWNWNWWEEEEWWEEEEWNWNWNWWEEEEWWEEEEW

A2(B)CDEF2(G)

1
A2(3(4(5(A))))ZY
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZY
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZY
A2(3(AAAAA)AAAAA)AAAAA)AAAAA))ZY
Case #1: 1 1
*/