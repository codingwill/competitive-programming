#include <bits/stdc++.h>

using namespace std;
int chil[5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        chil[input]++;
    }
    int chilCopy[5];
    copy(chil, chil+5, chilCopy);
    int total = chil[4];
    total += chil[3];
    chil[1] -= min(chil[3], chil[1]);
    total += min(chil[2], (int)ceil((double)chil[1]/2));
    chil[2] -= min(chil[2], (int)ceil((double)chil[1]/2));
    chil[1] -= min(chilCopy[2]*2, (int)ceil((double)chil[1]));
    total += ceil((double)chil[2]/2) + ceil((double)chil[1]/4);
    cout << total << '\n';
    return 0;
}