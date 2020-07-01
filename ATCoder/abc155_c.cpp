#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> vote;
    vector<string> kode;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        vote[input]++;
        if (vote[input] == 1) kode.push_back(input);
    }
    int maks = -1;
    vector<string> maks_str;
    for (int i = 0; i < kode.size(); i++)
    {
        if (maks < vote[kode[i]])
        {
            maks_str.clear();
            maks_str.push_back(kode[i]);
        }
        else if (maks == vote[kode[i]])
        {
            maks_str.push_back(kode[i]);
        }
        maks = max(maks, vote[kode[i]]);
    }
    //cout << "Jawaban: " << maks_str.size() << endl;
    if (maks_str.size() == 1) cout << maks_str[0] << '\n';
    else
    {
        sort(maks_str.begin(), maks_str.end());
        for (int i = 0; i < maks_str.size(); i++)
        {
            cout << maks_str[i] << '\n';
        }
    }



}