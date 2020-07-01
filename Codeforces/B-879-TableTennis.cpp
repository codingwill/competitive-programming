#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long int;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    queue<int> a;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push(input);
    }
    if (k >= n)
    {
        cout << n << '\n';
        return 0;
    }

    int win = a.front();
    a.pop();
    int count = 0;
    while(true)
    {
        if (win > a.front())
        {
            a.push(a.front());
            a.pop();
            count++;
            if (count == k) break;
        }
        else
        {
            count = 1;
            a.push(win);
            win = a.front();
            a.pop();
        }
    }
    cout << win << '\n';
    //5 2
    //1 4 3 5 2
    return 0;
}


