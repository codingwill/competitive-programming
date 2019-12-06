#include <bits/stdc++.h>

using namespace std;
	

int main()
{
	int a, b;
	cin >> a >> b;
	a = max(a, b);
	b = min(a, b);
	for (int i = a; i < a*b; i++)
	{
		if (i % a == 0 && i != a)
		{
			for (int c = b; c < a*b; c++)
			{
				if (c % b == 0)
				{
					if (c == i)
					{
						cout << c << '\n';
						i = a*b;						
					}
				}
			}
		}
	}
}	

