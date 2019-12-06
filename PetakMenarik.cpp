#include <bits/stdc++.h>

using namespace std;
/*
struct aStruct
{
    int baris, kolom;
};

bool kolomKecil(struct a, struct b)
{
    return a.kolom < b.kolom;
}
*/
int main()
{
    int index = 0, arr[101][101];
    int n, m, k;
    //aStruct a[10001];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int j = 0; j < m; j++)
    {
        int tetangga = 1;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                tetangga *= arr[i+1][j];
            }
            else if (i == n-1)
            {
                tetangga *= arr[i-1][j];
            }
            else
            {
                tetangga *= arr[i-1][j] * arr[i+1][j];
            }
            
            if (j == 0)
            {
                tetangga *= arr[i][j+1];
            }
            else if (j == m-1)
            {
                tetangga *= arr[i][j-1];
            }
            else
            {
                tetangga *= arr[i][j-1] * arr[i][j+1];
            }
            cout << "Index = " << i << " " << j  << endl;
            if (tetangga == k)
            {
                cout << i+1 << " " << j+1 << "\n";
                return 0;
            }
        }
    }
    cout << "0 0" << "\n";    
    return 0;

}