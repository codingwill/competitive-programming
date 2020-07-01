#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int pin[n];
        int pinBaru[n];
        for (int i = 0; i < n; i++)
        {
            //int input;
            cin >> pin[i];
            /*
            pin[i][0] = input/1000;
            pin[i][1] = (input % 1000)/100;
            pin[i][2] = (input % 100)/10;
            pin[i][3] = (input % 10);
            */
        }
        sort(pin, pin+n);
        pinBaru[0] = pin[0];
        for (int i = 1; i < n; i++)
        {
            pinBaru[i] = pin[i];
            if (pin[i] == pin[i-1])
            {
                if (pin[i] % 10 >= 5 && pinBaru[i-1] % 10 > 0)
                {
                    pinBaru[i] = pinBaru[i-1]--;
                }
                else if (pin[i] % 10 < 5 && pinBaru[i-1] % 10 < 9)
                {
                    pinBaru[i] = pinBaru[i-1]++;
                }
                else if ((pin[i] % 100)/10 >= 5 && (pinBaru[i-1] % 100)/10 > 0)
                {
                    pinBaru[i] = pinBaru[i-1]--;
                }
                else if ((pin[i] % 100)/10 < 5 && (pinBaru[i-1] % 100)/10 < 9)
                {
                    pinBaru[i] = pinBaru[i-1]++;
                }
                else if ((pin[i] % 1000)/100 >= 5 && (pinBaru[i-1] % 1000)/100 > 0)
                {
                    pinBaru[i] = pinBaru[i-1]--;
                }
                else if ((pin[i] % 1000)/100 < 5 && (pinBaru[i-1] % 1000)/100 < 9)
                {
                    pinBaru[i] = pinBaru[i-1]++;
                }
                else if (pin[i]/ 1000 >= 5 && pinBaru[i-1] / 1000 > 0)
                {
                    pinBaru[i] = pinBaru[i-1]--;
                }
                else if (pin[i] / 1000 < 5 && pinBaru[i-1] /1000 < 9)
                {
                    pinBaru[i] = pinBaru[i-1]++;
                }

            }
        }
    }
}