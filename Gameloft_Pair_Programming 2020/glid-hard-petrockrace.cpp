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

bool tupleSort(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    return get<2>(a) > get<2>(b);
}

using ll = long long int;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<vector<int>> vec;
    vector<int> posAwal, kec;
    string input;
    for (int i = 0; i < t; i++)
    {
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            if (input[j] != '.')
            {
                posAwal.push_back(j);
                kec.push_back(input[j] -'0');
                //cout << posAwal[0] << endl;
                vector<int> temp;
                for (int k = 0; k < input.length(); k++)
                {
                    if (k != j)
                    {
                        temp.push_back(-1);
                    }
                    else
                    {
                        temp.push_back(input[j] - '0');
                        //cout << input[j] - '0';
                    }
                }
                vec.push_back(temp);
                temp.clear();
            }
        }
        
        vector<int> ans;
        int pos;
        for (int k = 0; k < 5; k++)
        {
            for (int y = 0; y < input.length(); y++)
            {
                ans.push_back(-1);
            }
            for (int x = 0; x < vec.size(); x++)
            {
                if (k > 0)
                {
                    pos = posAwal[x] + kec[x] * (k-1);
                    int temp = vec[x][pos];
                    vec[x][pos] = -1;
                    pos = posAwal[x] + kec[x] * k;
                    vec[x][pos] = temp;
                    cout <<  pos << endl;
                    //cout << 't' << endl;
                }
            }
            
            for (int x = 0; x < input.length(); x++)
            {
                for (int j = 0; j < vec.size(); j++)
                {
                    if (vec[j][x] != -1)
                    {
                        ans[x] += vec[j][x];
                    }
                }
                if (ans[x] > -1)
                {
                    ans[x] += 1;
                }
            }
            
            for (int j = 0; j < vec[i].size(); j++)
            {
                if (ans[j] == -1)
                {
                    cout << '.';
                }
                else
                {
                    cout << ans[j];
                }
                
            }
            cout << '\n';
            ans.clear();
        }
    }
    //cout << vec.size() << endl;

    //cout << 't' << endl;
}