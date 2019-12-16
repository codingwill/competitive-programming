#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a;
    cout << "Nilai dari a adalah ";
    cin >> a;
    cout << "Address dari a adalah " << &a << endl;

    int &b = a;
    int &c = b;
    
    cout << "Nilai b = " << b << endl;
    cout << "Nilai c = " << c << endl;

    cin.get();
    return 0;
}