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
    int t;
    cin >> t;
    while (t--)
    {
        string p, h;
        cin >> p >> h;
        bool pAksen[p.length()];
        int hLen = h.length(), pLen = p.length();
        int count;
        for (int i = 0; i <= hLen - pLen; i++)
        {
            //cout << h.length() << endl;
            memset(pAksen, 0, sizeof(pAksen));
            count = 0;
            for (int j = i; j < p.length()+i; j++)
            {
                //cout << "asd" << endl;
                for (int k = 0; k < p.length(); k++)
                {
                    if (!pAksen[k])
                    {
                        if (p[k] == h[j])
                        {
                            //cout << p[k] << " " << h[j] << '\n';
                            //cout << "a" << endl;
                            pAksen[k] = true;
                            count++;
                            break;
                        }
                    }
                }
            }
            if (count == p.length())
            {
                //cout << i << endl;
                cout << "YES" << '\n';
                break;
            }
        } 
        //cout << count << '\n';
        if (count == p.length()) continue;
        cout << "NO" << '\n';
        
    }
    return 0;
}