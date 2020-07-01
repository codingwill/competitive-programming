#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string command;
    cin >> command;
    int bisaBalik = 0;
    for (int i = 0; i < command.length(); i++)
    {
        for (int j = i + 1; j < command.length(); j++)
        {
            int x = 0, y = 0;
            for (int k = i; k <= j; k++)
            {
                if (command[k] == 'U')
                {
                    y++;
                }
                else if (command[k] == 'D')
                {
                    y--;
                }
                else if (command[k] == 'L')
                {
                    x--;
                }
                else if (command[k] == 'R')
                {
                    x++;
                }
            }
            if (y == 0 && x == 0)
            {
                bisaBalik++;
            }
        }
    }
    cout << bisaBalik << endl;
    return 0;
}