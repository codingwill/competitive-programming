#include <bits/stdc++.h>

using namespace std;

long long int fungsiTotal(long long int a)
{
    if (a <= 0)
        return 0;
    if (a == 1)
        return 1;
    return a + fungsiTotal(a-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char c[k];
    vector<long long int> batas;
    bool ada;
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++)
    {
    	ada = false;
        for (int j = 0; j < k; j++)
        {
            if (s[i] == c[j])
            {
                ada = true;
            }
        }
        if (!ada)
        {
        	batas.push_back(i);
		}
        else if (ada && i == 0)
        {
            batas.push_back(-1);
        }
    }
    long long int hasil = 0;
    if (batas.size() < n)
    {
        int batasAkhir = batas.size() - 1;
        if (batas[batasAkhir] != n-1)
        {
            batas.push_back(n);
        }
        batasAkhir += 1;
        for (int i = 0; i < batasAkhir; i++)
        {
            if (batas[i] > 0 && i == 0)
            {
                hasil += fungsiTotal(batas[0]);
                continue;
            }
            hasil += fungsiTotal(batas[i+1] - batas[i] - 1);
        }
    }
    cout << hasil << "\n";
    return 0;
}
