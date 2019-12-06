#include <bits/stdc++.h>
#define ll long long
/*
CODE by wkwkwill
*/
using namespace std;

ll int fact(int a)
{
    if (a == 0)
        return 1;
    return a * fact(a-1);
}

bool kombin[3022][3022];
ll int nilaiKombin[3022][3022];

ll int unfairness(ll int arr[], int n, int k)
{
    ll int index[n];
    for (int i = 0; i < n; i++)
    {
        index[i] = i;
    }
    ll int total = 0;
    ll int minim;
    int it = 0; 
    ll int permutasi = fact(n)/fact(n-k);
    while (it < permutasi)
    {
        total = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = k; j < n; j++)
            {
                if (kombin[index[i]][index[j]] || kombin[index[j]][index[i]])
                {
                    
                }
                //cout << arr[i] << "-" << arr[j] << endl;
                total += abs(arr[index[i]] - arr[index[j]]);
                nilaiKombin[index[i]][index[j]] = total;
                nilaiKombin[index[j]][index[i]] = total;
                kombin[index[i]][index[j]] = true;
                kombin[index[j]][index[i]] = true;
            }
        }
        if (it == 0)
            minim = total;
        else
            minim = min(minim, total);
        next_permutation(index, index+n);
        it++;
    }
    return minim;
}


int main()
{
    int n, k;
    cin >> n >> k;
    ll int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << unfairness(num, n, k) << endl;
}