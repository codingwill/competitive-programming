#include <bits/stdc++.h>

using namespace std;

bool highToLow(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    int grade[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i];
        sum += grade[i];
    }
    double rata = (double)sum / n;
    if (rata >= 4.5f)
    {
        cout << "0" << endl;
        return 0;
    }
    sort(grade, grade+n);
    int i = 0;
    while (rata < 4.5f && grade[i] != 5 && i < n)
    {
        sum = sum + (5 - grade[i]);
        rata = (double)sum / n;
        i++;
    }
    if (rata >= 4.5f)
    {
        cout << i << endl;
    }
}