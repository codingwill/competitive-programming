#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        string input;
        cin >> input;
        if (input == "Tetrahedron")
            ans += 4;
        else if (input == "Cube")
            ans += 6;
        else if (input == "Octahedron")
            ans += 8;
        else if (input == "Dodecahedron")
            ans += 12;
        else if (input == "Icosahedron")
            ans += 20; 
    }
    cout << ans << "\n";
    return 0;
}