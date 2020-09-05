#include <bits/stdc++.h>
using namespace std;

void solve();

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	solve();
	
	return 0;
}

void solve()
{
	int n;
    cin >> n;
    map<string, int> address;
    for (int i = 0; i < n; ++i)
    {
        string input;
        cin >> input;
        if (address[input] == 0)
        {
            cout << "OK" << '\n';
        }
        else
        {
            cout << input << address[input] << '\n';
        }
        address[input]++;
    }
}
