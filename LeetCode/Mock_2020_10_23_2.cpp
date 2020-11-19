#include <bits/stdc++.h>

using namespace std;

int Random(int minim, int maks)
{
    return rand() % maks + minim;
}

vector<vector<bool>> generateSoal(int N, int M)
{
    vector<vector<bool>> papan(N, vector<bool>(N, true));
    for (int i = 0; i < papan.size(); ++i)
    {
        for (int j = 0; j < papan.size(); ++j)
        {
            if (M == 0) break;
            cout << Random(0, N * N) << '\n';
            if (Random(0, N * N) <= M)
            {
                papan[i][j] = false;
                M--;
            }
        }
        if (M == 0) break;
    }
    if (M > 0)
    {
        for (int i = 0; i < papan.size(); ++i)
        {
            for (int j = 0; j < papan.size(); ++j)
            {
                if (M == 0) break;
                if (papan[i][j]) 
                {
                    papan[i][j] = false;
                    M--;
                }
            }
            if (M == 0) break;
        }
    }
    return papan;
    
    
}

int main()
{
    srand(time(NULL));
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a = generateSoal(n, m);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); ++j)
        {
            if (a[i][j]) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}