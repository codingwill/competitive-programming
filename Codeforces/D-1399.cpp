#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/08/19
*/
using namespace std;
using ll = long long int;

ll BIG = 1e18 + 1;
ll MOD = 1e9 + 7;

void solve();

ll fastpow(ll x, ll y, ll n = BIG) 
{
    x %= n;
    ll ans = 1;
    while (y > 0) 
    {
        if (y & 1) ans = (ans * x) % n;
        x = (x * x) % n;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, queue<int>> subseq;
        int count = 1;
        vector<int> ans;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i == 0)
            {
                subseq[s[i]].push(count);
                ans.push_back(count);
            }
            else
            {
                if (s[i] == '0')
                {
                    if (subseq['1'].empty()) 
                    {
                        count++;
                        subseq['0'].push(count);
                        ans.push_back(count);
                    }
                    else if (!subseq['1'].empty())
                    {
                        int index = subseq['1'].front();
                        subseq['1'].pop();
                        subseq['0'].push(index);
                        ans.push_back(index);
                    }
                }
                else
                {
                    if (subseq['0'].empty()) 
                    {
                        count++;
                        subseq['1'].push(count);
                        ans.push_back(count);
                    }
                    else if (!subseq['0'].empty())
                    {
                        int index = subseq['0'].front();
                        subseq['0'].pop();
                        subseq['1'].push(index);
                        ans.push_back(index);
                    }
                }
            }
        }
        cout << count << '\n';
        for (int n : ans) cout << n << ' ';
        cout << '\n';
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
	return 0;
}

        /*
        stack<char> prevSub;
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (i == 0)
            {
                count++;
                prevSub.push(s[i]);
                continue;
            }
            if (prevSub.empty())
            {
                count++;
                prevSub.push(s[i]);
            }
            else if (s[i] == '0')
            {
                
            }
        }
        */