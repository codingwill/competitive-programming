#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    
    while(t--)
    {
        
        cin >> n;
        vector<int> p;
        vector<int>::iterator totMedal;
        for (int i = 0; i < n; i++)
        {
            int input; cin >> input;
            p.push_back(input);
        }
        int nMedal = (n-1)/2;
        if (p[nMedal] == p[nMedal+1])
        {
            totMedal = lower_bound(p.begin(), p.end(), p[nMedal]) - 1;
        }
        nMedal = totMedal - p.begin();
        nMedal++;
        int nGold = (nMedal/3) - 1;
        if (p[nGold] == p[nGold+1])
        {
            
            vector<int>::iterator totGold = lower_bound(p.begin(), p.end(), p[nGold]) - 1;
            nGold = totGold - p.begin();
        }

    }
}