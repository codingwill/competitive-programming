#include <bits/stdc++.h>
#include <vector>
#include <chrono>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
using namespace std::chrono;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}
using ll = long long int;

unordered_map<int, int> terisi; //koordinat, 1 = terisi || 0 = no

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> tree;
    vector<ll> people;
    for (ll i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        tree.push_back(input);
        terisi[input] = 1;
    }
    auto start = high_resolution_clock::now(); 
    ll treeNum = 0;
    ll rotation = 0;
    ll batasMFlex = m;
    ll distance = 0;
    for (ll i = 0; i < batasMFlex; i++)
    {
        if (i % n == 0) rotation++;
        treeNum = i % n;
        ll pepPos;
        if (rotation % 2 == 1)
        {
            pepPos = tree[treeNum] - ceil((float)rotation/2);
        }
        else
        {
            pepPos = tree[treeNum] + ceil((float)rotation/2);
        }
        distance += abs(pepPos-tree[treeNum]);
        if (terisi[pepPos] == 1)
        {
            //cout << "wkwk" << endl;
            distance -= abs(pepPos-tree[treeNum]);
            batasMFlex++;
            continue;
        }
        people.push_back(pepPos);
        terisi[pepPos] = 1;
        
    }
    cout << distance << '\n';
    for (ll i = 0; i < m-1; i++)
    {
        cout << people[i] << ' ';
    }
    cout << people[m-1] << '\n';
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    //cout << "Time taken by function: " << duration.count()/1000 << " ms" << endl;
    return 0;
}

/*
TC1
2 1 2 1 1 1 = 8
1 5
0 2 4 6 -1 3 
1 1 1 1 2 2 = 8 

TC2
2 1 1 1 2 = 7
0 1 3
-1 2 4 -2 5
wrong answer Integer parameter [name=res] equals to 0, violates the range [1, 1000000000000000000]
TC1 own
1 5
0 4 2 6 -1 3
1 1 1 1 2 2 = 8
*/