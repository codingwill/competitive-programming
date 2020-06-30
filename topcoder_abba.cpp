#include <bits/stdc++.h>

using namespace std;

class ABBA
{
public:
    string canObtain(string a, string b)
   	{
        while (b.length() > a.length() && b != a)
        {
            if (b[b.length()-1] == 'A')
            {
                b.erase(b.length()-1, 1);
            }
            else
            {
                b.erase(b.length()-1, 1);
                reverse(b.begin(), b.end());
            }
        }
        if (a == b) return "Possible";
        return "Impossible";  
    }
};

int main()
{
    string a, b;
    cin >> a >> b;
    ABBA solution;
    cout << solution.canObtain(a, b) << '\n';
}