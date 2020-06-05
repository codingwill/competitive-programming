#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/04
*/
using namespace std;
using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s1, s2;
        int n;
        cin >> n;
        vector<int> a, v1, v2;
        for (int i = 0; i < n; ++i)
        {
            int input;
            cin >> input;
            a.push_back(input);
            v1.push_back(input);
        }
        sort(v1.begin(), v1.end());
        bool can = false;
        int k = -1;
        for (int i = 1; i < 1024; ++i)
        {
            for (int j = 0; j < a.size(); ++j)
            {
                v2.push_back(a[j] ^ i);
            }
            sort(v2.begin(), v2.end());
            if (v1 == v2)
            {
                can = true;
                k = i;
                break;
            }
            v2.clear();
        }
        if (can) cout << k << '\n';
        else cout << "-1" << '\n';
        //cout << "wkwk" << endl;
        a.clear();
        v1.clear();
        v2.clear();
    }
}
/*
1 0 2 3
0001
0000
0010
0011

0001 xor 0001 = 0000
0000 xor 0001 = 0001


*/