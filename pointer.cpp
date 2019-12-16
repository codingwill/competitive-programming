#include <bits/stdc++.h>

using namespace std;
struct Biodata
{
    string nama;
};


void passByReference(struct Biodata &a)
{
    a.nama = "Willy";
}


void passByReferencePointer(struct Biodata *a)
{
    a->nama = "Aufa";
}




int main()
{
    int c = 4;
    Biodata biodata = {"Hafidh"};
    cout << "biodata awal adalah " << biodata.nama << endl;
    passByReference(biodata);
    cout << "biodata setelah fungsi passByReference dieksekusi " << biodata.nama << endl;
    passByReferencePointer(&biodata);
    cout << "biodata setelah fungsi passByReferencePointer dieksekusi " << biodata.nama << endl;
}