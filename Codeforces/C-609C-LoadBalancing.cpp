#include <bits/stdc++.h>
//I DON'T EVEN KNOW WHAT THIS IS
#define Willy using
#define Indrayana namespace
#define Komara std

Willy Indrayana Komara;

//just to make my life easier
#define for(i, n, k) for (int i = (int)(k); i<(int)(n); i++)
#define setp(n) fixed << setprecision(n)

//custom data type
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    int n;
    cin >> n;
    vi server;
    double average = 0;
    double sum = 0;
    //ll rata[2];
    for (i, n, 0)
    {
        int input;
        cin >> input;
        sum += input;
        server.push_back(input);
    }
    //sort(server.begin(), server.end());
    average = sum/n;
    /*
    if (average - (int)average < 1e-3)
    {
        rata[0] = average; //batas bawah
        rata[1] = average; //batas atas
    }
    else
    {
        rata[0] = average;
        rata[1] = ceil(average);
    }
    vi::iterator batas;
    batas = lower_bound(server.begin(), server.end(), rata[1]);
    ll batasInt = batas-server.begin();
    */
    ll selisihAtas = 0, selisihBawah = 0;
    for(i, n, 0)
    {
        if (server[i] < average)
        {
            selisihBawah += abs(server[i] - average);
        }
        else
        {
            selisihAtas += abs(server[i] - average);
        }
    }
    cout << max(selisihBawah, selisihAtas) << endl;
    return 0;
}