#include <bits/stdc++.h>
using namespace std;



int main()
{
	int t;
	cin >> t;
	int bad[t];
	for (int i = 0; i < t; i++)
	{
		
		int n;
		cin >> n;
		bool badDay = false;
		int a[n], nBad = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int j = 0; j < n-1; j++)
		{
			badDay = false;
			for (int k = j+1; k < n; k++)
			{
				if (a[j] > a[k])
				{
					badDay = true;
					break;
				}
					
			}
			if (badDay && n > 1)
				nBad++;
		}
		bad[i] = nBad;
	}
	
	for (int i = 0; i < t; i++)
	{
		cout << bad[i] << endl;
	}
}
