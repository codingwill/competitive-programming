#include <bits/stdc++.h>
 
//GAJE CONSTANT
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> myMap;
    for (int i = 0; i < 10; i++)
    {
        int key;
        cin >> key;
        myMap[key]++;
    }
    int nilai = 15;
    cout << "Frekuensi nilai " << nilai << " adalah " << myMap[nilai] << endl;
}