#include <bits/stdc++.h>
/*
** Author: wkwkwill (Willy I. K.)
** 2020/06/25
*/

using namespace std;
using ll = long long int;

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getMinConnectionChange' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY connection as parameter.
 */

vector<bool> visited(500000);

int countGraph(vector<int> a[], int size)
{
    queue<int> nodes;
    fill(visited.begin(), visited.end(), false);
    ll count = 0;
    //traverse (BFS)
    for (int i = 0; i < size; ++i)
    {
        //cout << 't' << endl;
        if (!visited[i+1])
        {
            nodes.push(i+1);
            visited[i+1] = true;
            ++count;
        }
        while(!nodes.empty())
        {
            int curNode = nodes.front();
            for (int j = 0; j < a[curNode].size(); ++j)
            {
                if (!visited[a[curNode][j]])
                {
                    nodes.push(a[curNode][j]);
                    visited[a[curNode][j]] = true;
                }
            }
            nodes.pop();
        }
        //cout << 't' << endl;
    }
    return count;
}

int getMinConnectionChange(vector<int> connection) 
{
    bool adaTerminal = false;
    vector<int> adj[connection.size()+5];
    //adj mat
    for (int i = 0; i < connection.size(); ++i)
    {
        //cout << 't' << endl;
        if (connection[i] == i+1) adaTerminal = true;
        adj[connection[i]].push_back(i+1);
        adj[i+1].push_back(connection[i]);
    }
    int ans = countGraph(adj, connection.size());
    if (adaTerminal) --ans;
    cout << ans << endl;
    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string connection_temp_temp;
    getline(cin, connection_temp_temp);

    vector<string> connection_temp = split(rtrim(connection_temp_temp));

    vector<int> connection(n);

    for (int i = 0; i < n; i++) {
        int connection_item = stoi(connection_temp[i]);

        connection[i] = connection_item;
    }

    int result = getMinConnectionChange(connection);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
