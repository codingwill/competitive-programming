#include <bits/stdc++.h>
#define for(i, n) for(int i = 0; i < (int) (n); i++)
using namespace std;

int main()
{
    string s;
    int m, l, r, k;
    cin >> s >> m;
    string cyclic;
    string sisa;
    while (m--)
    {
        cin >> l >> r >> k;
        l = l-1;
        r = r-1;
        s.replace(l, r-l + 1, s.substr(r + 1 - (k % (r-l + 1)), k % (r-l+1)) + s.substr(l, (r-l+1) - (k % (r-l+1))));
    }
    cout << s.c_str() << "\n";
}