#include <bits/stdc++.h>

using namespace std;

typedef long long ull;
ull MaxSumDifference(ull a[], ull n, ull k) 
{ 
    vector<ull> finalSequence; 

    sort(a, a + n); 
    ull i;
    ull sum = 0;
    for (i = 0; i < k / 2; ++i) 
    { 
        finalSequence.push_back(a[i]);
        sum += a[i]; 
        finalSequence.push_back(a[n - i - 1]); 
        sum += a[n-i-1];
    } 
    if (k % 2 == 1)
    {
        finalSequence.push_back(a[i]);
        sum += a[i];
    }

    ull MaximumSum = 0; 
    ull j = 0;
    
    while (j < k-1)
    {
        MaximumSum += abs(finalSequence[j] - finalSequence[i]);
    }
    /*
    for (int i = 0; i < 4; i++)
    {
        cout << finalSequence[i] << " ";
    }
    */
    //cout << finalSequence[1] << endl;
    return MaximumSum; 
} 

/*
1 13 2 11
12 + 1 + 10 + 11 + 2 + 9
*/

int main()
{
    int n, k;
    cin >> n >> k;
    ull arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ull hasil[k];
    int kiri = 0, kanan = n-1;
    /*
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            hasil[i] = arr[kiri];
            kiri++;
        }
        else
        {
            hasil[i] = arr[kanan];
            kanan--;
        }
    }
    
    int count = 0;
    for (int i = 0; i < k-1; i++)
    {
        count += abs(hasil[i] - hasil[i+1]);
    }
    */
    cout << MaxSumDifference(arr, n, k) << endl;
    return 0;
}