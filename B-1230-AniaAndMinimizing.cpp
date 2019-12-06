#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int digit, maxGantiDigit;
	cin >> digit >> maxGantiDigit;
	string bigIntStr;
	cin >> bigIntStr;
	//vector<int> bigInt(digit);
	if (digit >= 1)
	{
        if (digit == 1 && maxGantiDigit > 0)
        {
            cout << 0 << endl;;
            return 0;
        }
		for (int i = 0; i < digit; i++)
		{
			if (maxGantiDigit != 0)
			{
				if (i == 0 && (int)(bigIntStr[i] - '0') > 1)
				{
					bigIntStr.replace(i, 1, "1");
					maxGantiDigit--;
				}
				else if (i != 0 && (int)(bigIntStr[i] - '0') > 0)
				{
					bigIntStr.replace(i, 1, "0");
					maxGantiDigit--;
				}		
			}
				//bigInt[i] = (int)(bigIntStr[i] - '0');
			
		}
		cout << bigIntStr.c_str();
	}
	cout << endl;
	
}