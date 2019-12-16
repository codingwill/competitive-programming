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
    bool possible = false;
    bool change = true;
    while (t--)
    {
        change = true;
        possible = false;
        string s, c;
        cin >> s >> c;
        int batas;
        if (s.length() > c.length()) 
        {
            batas = c.length();
        }
        else
        {
            batas = s.length();
        }
        int swapIndex;
        bool semuaSama = true;
        bool semuaKecil = true;
        bool semuaBesar = true;
        for (int i = 0; i < batas; i++)
        {
            if ((int)s[i] > (int)c[i])
            {
                semuaSama = false;
                semuaKecil = false;
            }
            else if ((int)s[i] == (int)c[i])
            {
                semuaBesar = false;
                semuaKecil = false;
            }
            else
            {
                semuaSama = false;
                semuaBesar = false;
                break;
            }
            
        }
        //cout << s << endl;
        if (!semuaBesar && !semuaKecil && !semuaSama)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if ((int)s[i] > (int)c[i])
                {
                    swapIndex = i;
                    char smaller = s[i];
                    for (int j = i; j < s.length(); j++)
                    {
                        if ((int)smaller > (int)s[j])
                        {
                            smaller = s[j];
                            swapIndex = j;
                        }
                    }
                    swap(s[i], s[swapIndex]);
                    break;
                }
            }
            /*
            if (s < c) cout << s << '\n';
            else cout << "---" << '\n';
            continue;
            */
        }
        else if (semuaKecil)
        {
            //cout << s << '\n';
        }
        else if (semuaSama)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'A') continue;
                swapIndex = i;
                char smaller = s[i];
                for (int j = i+1; j < s.length(); j++)
                {
                    if ((int)smaller > (int)s[j])
                    {
                        smaller = s[j];
                        swapIndex = j;
                    }
                }
                swap(s[i], s[swapIndex]);
                break;
            }
            /*
            AMAZON AMAZON
            BMAZON BMAZON
            BBBBBA BBBBBA
            AAAAACB AAAAACB
            swap s[i] dengan s[j] < s[i] (minimum), skip s[i] = 'A'.
            */
            /*
            if (s < c) cout << "HUH" << '\n';
            else cout << "---" << '\n';
            continue;
            */
        }
        else if (semuaBesar)
        {
            /*
            ZZZB CAAA
            kalo ada s[i] yang lebih kecil c[0], maka swap s[i] dengan s[0]
            */
            char smaller = s[0];
            swapIndex = 0;
            for (int i = 1; i < s.length(); i++)
            {
                if ((int)smaller > (int)s[i])
                {
                    smaller = s[i];
                    swapIndex = i;
                }
            }
            swap(s[0], s[swapIndex]);
            /*
            if (s < c) cout << s << '\n';
            else cout << "---" << '\n';
            continue;
            */
        }
        bool kecil = false;
        for (int i = 0; i < batas; i++)
        {
            if (s[i] > c[i])
            {
                break;
            }
            else if (s[i] < c[i])
            {
                kecil = true;
                cout << s << '\n';
                break;
            }
        }
        if (!kecil) cout << "---" << '\n';

        /*
        for (int i = 0; i < s.length() - 1; i++)
        {
            if ((int)s[i] != (int)s[i+1])
            {
                for (int j = (int)'A'; j < (int)s[i+1]; j++)
                {
                    size_t found = s.find((char)j);
                    while (s.find((char)j))
                    {
                        if (found <= i+1) 
                        {
                            found++; continue;
                        }
                        swap(s[i+1], s[found]);
                        break;
                    }
                }
            }
        }
        */
        //if (!possible && !change) cout << "---" << '\n';
        //if (!change)
    }
    return 0;
}