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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, s;
        cin >> n >> s;
        ll verse[n];
        ll sumTime = 0;
        ll longest = INT64_MIN;
        ll index = 0;
        bool foundSkip = false;
        for (ll i = 0; i < n; i++)
        {
            cin >> verse[i];   
        }
        /*
        for (ll i = 0; i < n; i++)
        {
            sumTime += verse[i];
            if (sumTime >= s)
            {
                if (i == n-1 && sumTime > s)
                {
                    index = i;
                    break;
                }
                else if (i == n-1 && sumTime == s)
                {
                    index = -1;
                    break;
                }
                if (verse[i] > verse[i+1])
                {
                    index = i;
                    break;
                }
                else 
                {
                    index = -1;
                }


            }
            else
            {
                index = -1;
            }
        }
        */
       /*
        longest = verse[0];
        for (ll i = 0; i < n; i++)
        {
            sumTime += verse[i];
            if (i > 0 && !foundSkip)
            {
                if (verse[i] > longest) index = i;
                longest = max(longest, verse[i]);
            }
            
            if (sumTime >= s && !foundSkip)
            {
                if (i == n-1)
                {
                    index = i;
                    foundSkip = true;
                }
                else if (longest > verse[i+1])
                {
                    sumTime -= verse[i];
                    foundSkip = true;
                }
                else
                {
                    foundSkip = true;
                }
            }
            if (foundSkip)
            {
                break;
            }
            if (i == n-1 && !foundSkip)
            {
                index = -1;
                foundSkip = true;
            }
        }
        */
        bool noSkip = false;
        longest = verse[0];
        for (ll i = 0; i < n; i++)
        {
            sumTime += verse[i];
            if (i > 0)
            {
                if (verse[i] > longest)
                {
                    index = i;
                    longest = verse[i];
                }
            }
            if (i == n-1 && sumTime <= s)
            {
                index = -1;
                noSkip = true;
            }
            if (noSkip)
            {
                break;
            }
            if (sumTime >= s)
            {
                if (i == n-1)
                {
                    index = -1;
                    break;
                }
                if (longest < verse[i+1])
                {
                    index = i+1;
                }
                break;
            }
            
        }
        index++;
        cout << index << '\n';
    }
    return 0;
}