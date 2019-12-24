#include <bits/stdc++.h>
#include <chrono> 

//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std

using ll = long long int;

Willy Indrayana Komara;

bool waktuMandat(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    while (m--)
    {
        int n, T, a, b;
        cin >> n >> T >> a >> b;
        vector<pair<int, int>> prob; //time needed & time (at) mandat
        int timeNeed[n], timeMandat[n];
        for (int i = 0; i < n; i++)
        {  
            int input;
            cin >> input;
            if (input == 0)
            {
                prob.push_back(make_pair(a, 0));
            }
            else
            {
                prob.push_back(make_pair(b, 0));
            }
        }
        for (int i = 0; i < n; i++)
        {
            int input;
            cin >> input;
            prob[i].second = input;
            timeMandat[i] = input;
        }
        sort(prob.begin(), prob.end(), waktuMandat);
        sort(timeMandat, timeMandat+n);
            
        for (int i = 0; i < n; i++)
        {
            cout << prob[i].first << " " << prob[i].second << " " << timeMandat[i] << endl;
        }
        

        int waktuJalan = 0;
        int solved = 0;

        for (int i = 0; i < n; i++)
        {
            waktuJalan += prob[i].first;
 
            if (waktuJalan > timeMandat[i])
            {
                break;
            }
            solved++;
        }
        cout << solved << '\n';
    }
}
/*
10
3 5 1 3
0 0 1
2 1 4
2 5 2 3
1 0
3 2
1 20 2 4
0
16
6 20 2 5
1 1 0 1 0 0
0 8 2 9 11 6
4 16 3 6
1 0 1 1
8 3 5 6
6 20 3 6
0 1 0 0 1 0
20 11 3 20 16 17
7 17 1 6
1 1 0 1 0 0 0
1 7 0 11 10 15 10
6 17 2 6
0 0 1 0 0 1
7 6 3 7 10 12
5 17 2 5
1 1 1 1 0
17 11 10 6 4
1 1 1 2
0
1
*/