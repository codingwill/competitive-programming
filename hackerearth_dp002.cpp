#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			temp.push_back(input);
		}
		v.push_back(temp);
		temp.clear();
	}
	/* debug
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	//DP Part
	//base case
	dp[0][0] = v[0][0];
	//Baris
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + v[i][0];
	}

	//Kolom
	for (int i = 1; i < m; i++)
	{
		dp[0][i] = dp[0][i-1] + v[0][i];
	}

	//Filling All Elements of Sum
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + v[i][j];
		}
	}
	/*
	// Debug
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	*/
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << dp[x-1][y-1] << '\n';
	}
	return 0;
}