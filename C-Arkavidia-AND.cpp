#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int hasil;
map<pair<int, int>, int> dp;
map<pair<int, int>, bool> isDP;
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int q, l, r;
        cin >> q;
        int index = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            l--; r--;
            for (int j = l; j <= r; j++)
            {
                if (isDP[{l, r}])
                    break;
                if (j == l)
                {
                    hasil = arr[j];
                    continue;
                }
                hasil = hasil & arr[j];
            }
            if (isDP[{l, r}])
            {
                cout << dp[{l, r}]  << "\n";
                cout << "DP USED" << endl;
            }
            else
            {
                isDP[{l, r}] = true;
                dp[{l, r}] = hasil;
                index++;
                cout << hasil << endl;
            }
        }
        //cout << q << endl;
    }
    //cout << (7 & 31) << endl;
}