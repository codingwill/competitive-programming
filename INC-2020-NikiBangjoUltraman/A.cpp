#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const ll BIG = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

int main(){
	int n,a[1002],b[1002];
	int tota=0,totb=0,cb=0;
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		tota += a[i];
	}
	
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	
	while(cb < n-1){
		//cout << cb << "  ";
		totb += b[cb];
		if(b[cb+1] > b[cb+2]){
			cb += 2;
		} else {
			cb += 1;
		}
		
	}
	
	tota -= a[n-1];
	tota += b[0];
	totb += b[n-1];
	
	//cout << tota << " " << totb << "\n";
	
	if(tota > totb){
		tota += a[n-1];
		cout << tota << "\n";
	} else {
		totb += a[n-1];
		cout << totb << "\n";
		
	}
	
	
	
	return 0;
}
