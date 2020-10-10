#include <bits/stdc++.h> 
using namespace std; 
  
string precisionCompute(int x, int y, int n) 
{ 
    string s = "";
    if (y == 0) 
    { 
        cout << "Infinite" << endl; 
        return ""; 
    } 
    if (x == 0) 
    { 
        return "0"; 
    } 
    if (n <= 0) 
    {  
        return to_string(x/y); 
    } 
  
    if (((x > 0) && (y < 0)) || ((x < 0) && (y > 0))) 
    { 
        cout << "-"; 
        x = x > 0 ? x : -x; 
        y = y > 0 ? y : -y; 
    } 
  
    int d = x / y; 
  
    for (int i = 0; i <= n; i++) 
    { 
        s += to_string(d); 
        x = x - (y * d); 
        if (x == 0) 
            break; 
        x = x * 10; 
        d = x / y; 
        if (i == 0) s += "."; 
    } 
    return s;
} 
  
// Driver Program 
int main() 
{ 
    int x = 22, y = 7, n = 15; 
    cout << precisionCompute(x, y, n); 
    return 0; 
} 