
# include <bits/stdc++.h>
 
using namespace std;
 
string s;
 
long long p[100009];
 
int main(){
	cin>>s;
	p[1]=1;
	p[0]=1;
	if(s[0]=='m' || s[0]=='w')cout<<0,exit(0);
	for(int i=1;i<s.size();i++){
		if(s[i]=='m' || s[i]=='w')cout<<0,exit(0);
		if(s[i]=='n' && s[i-1]=='n')p[i+1]=p[i-1];
		if(s[i]=='u' && s[i-1]=='u')p[i+1]=p[i-1];
		p[i+1]=(p[i+1]+p[i])%1000000007;
	}
	
	cout<<p[s.size()];
}