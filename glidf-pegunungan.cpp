#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t[5];
	for(int i = 0; i < 5; i++)
		cin >> t[i];
	string gunung[] = {"", "", "", "", ""};
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(i == 0){
				switch(t[j]){
					case 0:
						gunung[5-1-i] += ".";
						break;
					case 1:
						gunung[5-1-i] += "x";
						break;
					case 2:
						gunung[5-1-i] += "xxx";
						break;
					case 3:
						gunung[5-1-i] += "xxxxx";
						break;
					case 4:
						gunung[5-1-i] += "xxxxxxx";
						break;
					case 5:
						gunung[5-1-i] += "xxxxxxxxx";
						break;
				}
			}
			else if(i == 1){
				switch(t[j]){
					case 0:
						gunung[5-1-i] += ".";
						break;
					case 1:
						gunung[5-1-i] += ".";
						break;
					case 2:
						gunung[5-1-i] += ".x.";
						break;
					case 3:
						gunung[5-1-i] += ".xxx.";
						break;
					case 4:
						gunung[5-1-i] += ".xxxxx.";
						break;
					case 5:
						gunung[5-1-i] += ".xxxxxxx.";
						break;
 
				}
			}
			else if(i == 2){
				switch(t[j]){
					case 0:
						gunung[5-1-i] += ".";
						break;
					case 1:
						gunung[5-1-i] += ".";
						break;
					case 2:
						gunung[5-1-i] += "...";
						break;
					case 3:
						gunung[5-1-i] += "..x..";
						break;
					case 4:
						gunung[5-1-i] += "..xxx..";
						break;
					case 5:
						gunung[5-1-i] += "..xxxxx..";
						break;
 
				}
			}
			else if(i == 3){
				switch(t[j]){
					case 0:
						gunung[5-1-i] += ".";
						break;
					case 1:
						gunung[5-1-i] += ".";
						break;
					case 2:
						gunung[5-1-i] += "...";
						break;
					case 3:
						gunung[5-1-i] += ".....";
						break;
					case 4:
						gunung[5-1-i] += "...x...";
						break;
					case 5:
						gunung[5-1-i] += "...xxx...";
						break;
 
				}
			}
			else{
				switch(t[j]){
					case 0:
						gunung[5-1-i] += ".";
						break;
					case 1:
						gunung[5-1-i] += ".";
						break;
					case 2:
						gunung[5-1-i] += "...";
						break;
					case 3:
						gunung[5-1-i] += ".....";
						break;
					case 4:
						gunung[5-1-i] += ".......";
						break;
					case 5:
						gunung[5-1-i] += "....x....";
						break;
 
				}
			}
		}
	}
	for(int i = 0; i < 5; i++)
		cout << gunung[i] << endl;
	return 0;
}