#include<bits/stdc++.h>
#include<stdio.h>
#include <string>
using namespace std;
 
int main()
{
  int arr[4]={44,47,74,77};
  int n;
  cin>>n;
  if(n%4==0||n%7==0){cout<<"YES";return 0;}
  for(int i=0;i<8;i+=3)
  {
      for(int j=0;j<4;j++)
      {
          if(n%((i*100)+arr[j])==0){cout<<"YES";return 0;}
      }
      if(i==0)i++;
  }
 
  cout<<"NO";
 
 
}
 