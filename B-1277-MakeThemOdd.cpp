#include <bits/stdc++.h>
//number theory
using namespace std;
bool bisaDibagi[200005];

bool besarDulu(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first) return (a.second > b.second);
    return (a.first > b.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<long long int, long long int> a;
        vector<pair<long long int, long long int>> aSorting;
        for (int i = 0; i < n; i++)
        {
            long long int input;
            cin >> input;
            a[input] = 0;
        }
        for (map<long long int, long long int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            if (it->first % 2 == 0)
                aSorting.push_back(make_pair(it->first, it->second));
        }
        if (aSorting.empty())
        {
            cout << "0" << '\n';
            continue;
        }
        sort(aSorting.begin(), aSorting.end(), besarDulu);
        long long int count = 0;
        /*
        for (int i = 0; i < aSorting.size(); i++)
        {
            cout << aSorting[i].first << " " << aSorting[i].second << '\n';
        }
        */
        /*
        for (int i = 0; i < aSorting.size(); i++)
        {
            if (aSorting[i].second == 0) continue;
            if (aSorting[i].first % 2 == 1) continue;
            for (int j = i+1; j < aSorting.size(); j++)
            {
                if (ceil((log2((double)aSorting[i].first / aSorting[j].first))) == floor((log2((double)aSorting[i].first / aSorting[j].first))))
                //if (((double)aSorting[i].first / aSorting[j].first) & (((double)aSorting[i].first / aSorting[j].first)-1) == 0)
                {
                    cout << aSorting[i].first << " " << aSorting[j].first << '\n';
                    aSorting[i].second += aSorting[j].second;
                    aSorting[j].second = 0;
                }
            }
            
        }
        */
        for (int i = 0; i < aSorting.size(); i++)
        {
            //if (aSorting[i].second == 0) continue;
            if (aSorting[i].first % 2 == 1) continue;
            while (aSorting[i].first % 2 == 0)
            {
                //count++;
                aSorting[i].first /= 2;
                aSorting[i].second++;
                /*
                for (int j = i+1; j < aSorting.size(); j++)
                {
                    if (aSorting[i].first == aSorting[j].first)
                    {
                        aSorting[i].second += aSorting[j].second;
                        aSorting[j].second = 0;
                    }
                }
                */
            }
        }
        sort(aSorting.begin(), aSorting.end(), besarDulu);
        count += aSorting[0].second;
        for (int i = 0; i < aSorting.size()-1; i++)
        {
            if (aSorting[i].first != aSorting[i+1].first)
            {
                count += aSorting[i+1].second;
            }
            //cout << aSorting[i].first << " " << aSorting[i].second << endl;
        }
        /*
        for (int i = 0; i < aSorting.size(); i++)
        {
            cout << aSorting[i].first << " " << aSorting[i].second << '\n';
        }
        */
        cout << count << '\n';
    }
    return 0;
}
/*
45-21
24-12-6-3
16-8-4-2-1
*/