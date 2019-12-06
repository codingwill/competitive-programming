#include <bits/stdc++.h>

using namespace std;

struct LinkedList
{
    int value;
    LinkedList *penunjuk;
};

int main()
{
    LinkedList list1, list2, list3;
    list1.value = 10;
    list1.penunjuk = &list2;
    list2.value = 20;
    list2.penunjuk = &list3;
    list3.value = 30;
    list3.penunjuk = nullptr;
    cout << list1.value << endl;

    cout << list1.penunjuk->value << endl;    //equivalent
    cout << list2.value << endl;

    cout << list1.penunjuk->penunjuk->value << endl;
    cout << list2.penunjuk->value << endl;
    cout << list3.value << endl;
    return 0;
}