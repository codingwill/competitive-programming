#include<bits/stdc++.h>
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }
    int start = n;
    for (int i = 0; i < n; i++)
    {
        pq.push(a[i]);
        while (pq.top() == start)
        {
            cout << pq.top() << ' ';
            pq.pop();
            start--;
        }
        cout << '\n';
    }
}