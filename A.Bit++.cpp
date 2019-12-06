#include <bits/stdc++.h>

using namespace std;

int main()
{
	int nState;
	cin >> nState;
	int hasil = 0;
	for (int i = 0; i < nState; i++)
	{
		string statement;
		cin >> statement;
		int incSum = 0;
		for (int j = 0; j < statement.length(); j++)
		{
			if (statement[j] == '+')
			{
				incSum++;
			}
			else if (statement[j] == '-')
			{
				incSum--;
			}
		}
		if (incSum == 2)
			hasil++;
		else if (incSum == -2)
			hasil--;
	}
	cout << hasil << endl;
}
