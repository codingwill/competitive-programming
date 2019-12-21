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
    int n;
    cin >> n;
    string s, sOri;
    cin >> sOri;
    s = sOri;
    int B_count = 0, W_count = 0;
    bool W_ada = false, B_ada = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
        {
            W_ada = true;
            W_count++;
        } 
        else
        {
            B_ada = true;
            B_count++;
        }
    }
    if ((B_ada && !W_ada) || (!B_ada && W_ada))
    {
        cout << "0" << '\n';
        return 0;
    }
    if (W_count % 2 == 1 && B_count % 2 == 1)
    {
        cout << "-1" << '\n';
        return 0;
    }
    int W_cara = 0, B_cara = 0;
    vector<int> caraPola_B, caraPola_W;
    int minim;
    //ubah B jadi W -> jumlah caranya
    if (B_count % 2 == 0)
    {
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i] == 'B')
            {
                B_cara++;
                caraPola_B.push_back(i+1);
                s[i] = 'W';
                if (s[i+1] == 'W') s[i+1] = 'B';
                else s[i+1] = 'W';
            }
        }
    }
    else
    {
        B_cara = INT_MAX;
    }

    //cout << s << '\n';

    if (W_count % 2 == 0)
    {
        s = sOri;
        for (int i = 0; i < s.length()-1; i++)
        {
            if (s[i] == 'W')
            {
                //cout << s << endl;
                W_cara++;
                caraPola_W.push_back(i+1);
                s[i] = 'B';
                if (s[i+1] == 'B') s[i+1] = 'W';
                else s[i+1] = 'B';
            }
        }
    }
    else
    {
        W_cara = INT_MAX;
    }
    
    //cout << W_cara << " " << B_cara << endl;
    minim = min(W_cara, B_cara);
    //cout << minim << endl;
    if (minim <= 3*n)
    {
        cout << minim << '\n';
        for (int i = 0; i < minim - 1; i++) 
        {
            if (minim == B_cara)
                cout << caraPola_B[i] << " ";
            else
                cout << caraPola_W[i] << " ";
        
        }
        if (minim == B_cara) cout << caraPola_B[minim-1] << '\n';
        else cout << caraPola_W[minim-1] << '\n';
        //cout << s << '\n';
        return 0;
    }
    else
    {
        cout << "-1" << '\n';
        return 0;
    }
    
}
/*
BBWBWBBB
BBBWWBBB
BBBBBBBB

BWBWB
BWWBB
BBBBB

BWBBW
BBWBW
BBWWB
BBBBB

BBWBWW
*/