#include <bits/stdc++.h>
 
//BIAR MANTAB LAH YA
#define Willy using
#define Indrayana namespace
#define Komara std
 
Willy Indrayana Komara;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pair<int, int>> v; //posisi, val
    string s[t];
    for (int i = 0; i < t; i++)
    {
        cin.ignore();
        cin >> s[i];
    }
        
    for (int i = 0; i < t; i++)
    {
        
        for (int j = 0; j < s[i].length(); j++)
        {
            if (s[i][j] != '.')
            {
                v.push_back(make_pair(j, s[i][j] - '0'));
            }
        }

        //generator
        cout << s[i] << '\n';
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < v.size(); k++)
            {
                v[k].first += v[k].second;
            }
            for (int k = 0; k < s[i].length(); k++)
            {
                bool titik = true;
                int sum = 0;
                for (int l = 0; l < v.size(); l++)
                {
                    if (v[l].first == k)
                    {
                        titik = false;
                        sum += v[l].second;
                    }
                }
                if (!titik)
                {
                    sum = sum % 10;
                    cout << sum;
                }
                else
                {
                    cout << ".";
                }
                
            }
            if (j == 3 && i == t - 1) break;
            cout << "\n";
        }
        v.clear();
    }
}