#include <bits/stdc++.h>

using namespace std;

int main(){
    int SCL, SC;
    cin >> SCL >> SC;
    int SL[SC], SD[SC];
    int temp;
    for(int i = 0; i < SC; i++){
        cin >> SL[i] >> SD[i];
        for(int j = i; j > 0; j--){
            if((float)SD[j]/SL[j] > (float)SD[j-1]/SL[j-1]){
                temp = SD[j];
                SD[j] = SD[j-1];
                SD[j-1] = temp;
                temp = SL[j];
                SL[j] = SL[j-1];
                SL[j-1] = temp;
            }
        }
    }
    for (int i = 0; i < SC; i++)
    {
        cout << SL[i] << ' ' << SD[i] << endl;
    }
    temp = SCL;
    int dmg = 0;
    for(int i = 0; i < SC; i++){
        temp -= SL[i];
        if(temp >= 0)
            dmg += SD[i];
        else
            break;
    }
    cout << dmg << endl;
    return 0;
}