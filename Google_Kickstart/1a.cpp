
#include <bits/stdc++.h> 
using namespace std; 

bool** dp; 
  
void display(const vector<int>& v) 
{ 
    for (int i = 0; i < v.size(); ++i) 
        printf("%d ", v[i]); 
    printf("\n"); 
} 

void toBinary(vector<int> a, int i, int sum, vector<int>& p) 
{ 
    if (i == 0 && sum != 0 && dp[0][sum]) 
    { 
        p.push_back(a[i]); 
        display(p); 
        return; 
    } 
    if (i == 0 && sum == 0) 
    { 
        display(p); 
        return; 
    } 
  
    if (dp[i-1][sum]) 
    { 
        vector<int> b = p; 
        toBinary(a, i-1, sum, b); 
    } 
  
    if (sum >= a[i] && dp[i-1][sum-a[i]]) 
    { 
        p.push_back(a[i]); 
        toBinary(a, i-1, sum-a[i], p); 
    } 
} 
  
void traverse(vector<int> a, int n, int sum) 
{ 
    if (n == 0 || sum < 0) 
       return; 
  
    dp = new bool*[n]; 
    for (int i=0; i<n; ++i) 
    { 
        dp[i] = new bool[sum + 1]; 
        dp[i][0] = true; 
    } 
  
    if (a[0] <= sum) 
       dp[0][a[0]] = true; 
  
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < sum + 1; ++j) 
        {
            dp[i][j] = (a[i] <= j) ? dp[i-1][j] || dp[i-1][j-a[i]] : dp[i - 1][j]; 
        }
    }
    if (!dp[n-1][sum]) 
    { 
        return; 
    } 
    vector<int> p; 
    toBinary(a, n-1, sum, p); 
} 
  
int main() 
{ 
    vector<int> arr = {1, 2, 3, 5, 8, 13}; 
    int n = arr.size();
    int sum = 12; 
    traverse(arr, n, sum); 
    return 0; 
} 