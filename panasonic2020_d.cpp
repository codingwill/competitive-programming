#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0) v[j] = 0;
            else
            {
                if (j == n-1) v[j] += 1;
                for (int k = n-1; k >= 0; k--)
                {
                    if (v[k] == 2)
                    {
                        v[k] = 0;
                        v[k-1] += 1;
                    }
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            cout << v[j];
            //cout << (v[j] == 0 ? 'a' : 'b');
        }
        cout << endl;
    }
    return 0;
}

//aa == bb
//ab == ba

//aaa == bbb == ccc
//aab == bba == bbc == cca
//[aba] == aca == bab
//baa == [abb]
//[abc]
//

//aaaa
//aaab
//aabb
//abbb
//aaba
//abaa

//0

//00
//01

//000
//001
//010

//0000
//0001
//0010
//0011