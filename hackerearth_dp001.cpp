#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin >> n;
	ll a[100001];
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < 100000; i++)
	{
		a[i] = ((i % 1000000007) * (a[i-1] % 1000000007)) % 1000000007;
	}
	while (n--)
	{
		int input;
		cin >> input;
		cout << a[input] << '\n';
	}
	return 0;
}
