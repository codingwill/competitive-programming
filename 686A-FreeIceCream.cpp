#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, x;
    cin >> n >> x;
    long long int ice;
    int distressKids = 0;
    char mark;
    int a;
    while (n--)
    {
        cin >> mark >> ice;
        if (mark == '+')
        {
            x += ice;
        }
        else
        {
            if (ice <= x)
            {
                x -= ice;
            }
            else
            {
                distressKids++;
            }
        }
    }
    cout << x << " " << distressKids << "\n";
    return 0;
}