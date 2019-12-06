#include <iostream>
#include <string>

using namespace std;

string hallo(string a = " ")
{
    return "Halo " + a + "!\n"; 
}

int main()
{
    cout << hallo("Nandhika") + "wkwk" << endl;
    return 0;
}