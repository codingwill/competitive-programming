#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) 
        {
            int input;
            cin >> input;
            a.push_back(input);

        }
        sort(a.begin(), a.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
            {
                count++;
            }
            else break;
        }
        if (count % 2 == 1) cout << "Lucky\n";
        else cout << "Unlucky\n";
        a.clear();
    }
    return 0;
}