#include <bits/stdc++.h>

using namespace std;

string feeling(int i, int n)
{
    if (i == n)
        return "";
    if (i % 2 == 1)
    {
        return "that I love " + feeling(i+1, n);
    }
    else
    {
        return "that I hate " + feeling(i+1, n);
    }
}

int main()
{
    int n;
    cin >> n;
    if (n > 1)
        cout << "I hate " << feeling(1, n) << "it" << "\n";
    else
        cout << "I hate it " << "\n";
    return 0;
}