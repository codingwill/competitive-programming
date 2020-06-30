#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream  data("test.csv");
    string line;
    vector<vector<string> > parsedCsv;
    while(getline(data,line))
    {
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }

        parsedCsv.push_back(parsedRow);
    }
    cout << parsedCsv.size();
    //cout << parsedCsv[1][1] << endl;
}
