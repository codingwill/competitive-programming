#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    //int slen = input.length();
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'A' || input[i] == 'a' ||
            input[i] == 'O' || input[i] == 'o' || 
            input[i] == 'Y' || input[i] == 'y' ||
            input[i] == 'E' || input[i] == 'e' ||
            input[i] == 'U' || input[i] == 'u' ||
            input[i] == 'I' || input[i] == 'i')
        {
            input.erase(i, 1);
            i--;
        }
        else
        {
            if (input[i] <= 90)
                input[i] += 32; 
            input.insert(i, ".");
            //slen++;
            i++;
        }
        
    }
    cout << input.c_str() << endl;
}