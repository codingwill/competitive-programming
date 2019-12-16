#include <bits/stdc++.h>

using namespace std;

bool visited[5005];

int main()
{
    int n;
    cin >> n;
    vector<list<int>> edge;

    for (int i = 0; i < n; i++)
    {
        int input;
        list<int> node;
        cin >> input;
        input--;
        node.push_back(input);
        edge.push_back(node);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            //cout << "tes" << endl;
            if (edge[edge[edge[i].back()].back()].back() == i)
            {
                cout << "YES" << "\n";
                return 0;
            }
        }
        visited[i] = true;
        visited[visited[i]] = true;
        visited[visited[visited[i]]] = true;
    }
    cout << "NO" << "\n";
    return 0;
}