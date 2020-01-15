#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;



using ll = long long int;

struct Arr
{
    int minim;
    int maks;
    int l;
};

bool kecilDulu(Arr a, Arr b)
{
    return a.minim < b.maks;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Arr> s;
    for (int i = 0; i < n; i++)
    {
        int minim = INT32_MAX;
        int maks = INT32_MIN;
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int input;
            cin >> input;
            minim = min(minim, input);
            maks = max(maks, input);
            //s.push_back(input);
        }
        Arr temp = {minim, maks, l};
        s.push_back(temp);
    }
    //sort(s.begin(), s.end(), kecilDulu);
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i && s[i].l > 1) count++;
            if (s[i].minim < s[j].maks)
            {
                count++;
            }
        }
        //cout << s[i].minim << endl;
    }
    cout << count << '\n';
}
/*

9
9
1
7
5
8
9
9
8
0

4
= 69

sleepylol
1 1 2 4 3
1 2 3 4 -> 3*2 + 2 + 1 = 9

1, 1 = 1 * 2 = 2
1, 2 = 1
2, 1 = 0
1, 3 = 1
3, 1 = 0
2, 2 = 1 * 2 = 2
2, 3 = 0
3, 2 = 1
3, 3 = 0 * 2 = 0
sum = 7

*/