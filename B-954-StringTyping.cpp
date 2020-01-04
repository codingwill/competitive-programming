#include <bits/stdc++.h>
 
//GAJE CONSTANT
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
    string s;
    cin >> s;
    int count = 0;
    int minim = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        //aaaaaaa
        count = n;
        unsigned int found = s.find(s.substr(0, i+)1);
        found = s.find(s.substr(0, i+1), found+(i+1));
        //cout << found << endl;
        if (found == i+1)
        {
            count = (i+1+1) + (n - 2*(i+1));
        }
        if (count < minim)
        {
            minim = count;
        }
    }
    cout << minim << '\n';
    return 0;
}
