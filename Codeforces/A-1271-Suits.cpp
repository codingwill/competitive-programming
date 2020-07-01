#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

bool besarDulu(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tie, acc[2], jaket, versi[2];
    cin >> tie;
    for (int i = 0; i < 2; i++)
    {
        cin >> acc[i];
    }
    sort(acc, acc+2);
    cin >> jaket;
    for (int i = 0; i < 2; i++)
    {
        cin >> versi[i];
    }
    int count = 0;
    if (versi[0] > versi[1])
    {
        if (jaket - tie >= 0)
        {
            count += tie * versi[0];
            jaket -= tie;
            count += min(jaket, acc[0]) * versi[1];
            cout << count << '\n';
            return 0;
        }
        else
        {
            count += jaket * versi[0];
            cout << count << '\n';
            return 0;
        }
        
    }
    else if (versi[0] < versi[1])
    {
        if (jaket - acc[0] >= 0)
        {
            count += acc[0] * versi[1];
            jaket -= acc[0];
            count += min(jaket, tie) * versi[0];
            cout << count << '\n';
            return 0;
        }
        else
        {
            count += jaket * versi[1];
            cout << count << '\n';
            return 0;
        }
    }
    else
    {
        count += min(jaket, min(acc[0], tie)) * versi[0];
        //count += (jaket - min(jaket, min(acc[0], tie))) * versi[0]
        if (min(jaket, min(acc[0], tie)) == jaket)
        {
            cout << count << '\n';
            return 0;
        }
        else if (min(jaket, min(acc[0], tie)) == acc[0])
        {
            count += min((jaket-acc[0]), tie) * versi[0];
            cout << count << '\n';
            return 0;
        }
        else if (min(jaket, min(acc[0], tie)) == tie)
        {
            count += min((jaket-tie), acc[0]) * versi[0];
            cout << count << '\n';
            return 0;
        }
    }
}