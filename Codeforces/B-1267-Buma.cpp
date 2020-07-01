#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;
 
//JUST TO MAKE MY LIFE EASIER
#define for(i, n, k) for(int i = (int)(k); i < n; i++)

//TIPE DATA BENTUKAN

struct barisan
{
    char color;
    int count;
    int indexAkhir;
};

vector<barisan> kelompok;

bool elongate(int segIndexDepan, int segIndexBlkg)
{
    if (segIndexDepan < 0)
        return 1;
    if (kelompok[segIndexDepan].count + kelompok[segIndexBlkg].count >= 3)
    {
        if (kelompok[segIndexDepan].color == kelompok[segIndexBlkg].color)
            elongate(segIndexDepan-1, segIndexBlkg+1);
    }
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string ball;
    cin >> ball;
    int segment = 1;
    int kelCount = 0;
    for(i, ball.length() - 1, 0)
    {
        kelCount++;
        if (ball[i] != ball[i+1])
        {
            segment++;
            barisan input;
            //input.indexAkhir = i;
            input.color = ball[i];
            input.count = kelCount;
            kelompok.push_back(input);
            kelCount = 0;
        }
        if (i == ball.length() - 2 && ball[i] == ball[i+1])
        {
            kelCount++;
            barisan input;
            //input.indexAkhir = i+1;
            input.color = ball[i];
            input.count = kelCount;
            kelompok.push_back(input);
            kelCount = 0;
        }
        if (i == ball.length() - 2 && ball[i] != ball[i+1])
        {
            kelCount=1;
            barisan input;
            //input.indexAkhir = i+1;
            input.color = ball[i+1];
            input.count = kelCount;
            kelompok.push_back(input);
            kelCount = 0;
        }
    }
    if (segment % 2 == 0)
    {
        cout << "0" << "\n";
        return 0;
    }
    int target = segment / 2;
    if (kelompok[target].count + 1 >= 3)
    {
        if (elongate(target-1, target+1))
            cout << kelompok[target].count + 1 << "\n";
        else
            cout << "0" << "\n";
    }
    else
    {
        cout << "0" << "\n";
    }
    return 0;
}
