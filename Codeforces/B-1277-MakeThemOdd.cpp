#include <bits/stdc++.h>
//number theory
using namespace std;

//fungsi sebagai paramter komparasi sorting yang tipe datanya pair/tuple berdata dua/
//struct berdata dua. Prioritas komparasi pertama adalah kunci (pair pertama) yang
//diurutkan berdasarkan kunci terbesar, apabila sama, pair kedua yang diurutkan.
bool besarDulu(const pair<int, int> a, const pair<int, int> b)
{
    if (a.first == b.first) return (a.second > b.second);
    return (a.first > b.first);
}

int main()
{
    //disable sync sama fungsi-fungsi input I/O aka scanf/printf atau
    //disable pengiriman output ke library IO C.
    //Kegunaannya supaya fungsi I/O C++ lebih efisien. Kelemahannya jadi 
    //ga bisa campur-campur fungsi I/O dari C++ sama C.
    ios_base::sync_with_stdio(false);
    //buat flushing buffer cout sebelum fungsi cin atau meminta input. Cocok buat program
    //yang input sama output dicampur-campur/ga berurut kayak program ini (karena input
    //output ada di dalem while, jadi cin->cout->cin->cout
    //setelah pake fungsi ini nanti buffer output bakal ada di bawah input semua
    //aka cin->cin->cout->cout
    cin.tie(NULL);
    //banyak test case pada soal
    int t;
    cin >> t;
    //pengulangan sebanyak test case soal
    while (t--)
    {
        //banyak elemen array yang akan dibuat ganjil
        int n;
        cin >> n;
        //map buat nyimpen elemen-elemennya, nilai elemen sebagai kunci
        //total seluruh nilai elemen tertentu sebagai value.
        map<long long int, long long int> a;
        //vector dipakai untuk pengolahan elemen-elemen tertentu
        //supaya lebih fleksibel khususnya untuk sorting (karena map ga bisa
        //sorting berdasarkan value). Seharusnya pas input langsung pake
        //vector<pair> aja sih, ga perlu map dulu.
        vector<pair<long long int, long long int>> aSorting;
        //setiap elemen dari inputan akan dimasukkan sebagai kunci/keys
        //sedangkan nilainya akan diset 0 (supaya nanti bisa dipakai 
        //sebagai container untuk menghitung //jumlah cara pembagian oleh 2, 
        //sehingga dihasilkan angka ganjil).
        for (int i = 0; i < n; i++)
        {
            long long int input;
            cin >> input;
            a[input] = 0;
        }
        //copy semua elemen dalam container map ke dalam container vector, tapi 
        //hanya kunci yang genap saja yang dicopy. Kenapa? Karena kunci ganjil
        //ga perlu diolah (kita cuma mau menghitung banyak cara untuk mengubah
        //nilai genap menjadi ganjil. Kalo nilai ganjil dimasukkan ke vector cuma
        //menuhin memori jadinya.
        for (map<long long int, long long int>::iterator it = a.begin(); it != a.end(); ++it)
        {
            if (it->first % 2 == 0)
                aSorting.push_back(make_pair(it->first, it->second));
        }
        //cek apakah ada nilai ganjil dalam himpunan (container tidak kosong)
        //jika kosong, maka banyaknya cara mengubah nilai ganjil ke genap adalah
        //"0" (karena udah ganjil semua kan).
        if (aSorting.empty())
        {
            cout << "0" << '\n';
            continue;
        }
        long long int count = 0;
        //Melakukan pembagian seluruh kunci/nilai pertama oleh 2, hingga nilainya
        //menjadi ganjil. Nilai kedua akan diupdate sebanyak 1 ketika dilakukan pembagian
        //oleh 2 sebanyak 1x (nilai tsb menyatakan banyaknya cara pembagian oleh 2).
        for (int i = 0; i < aSorting.size(); i++)
        {
            if (aSorting[i].first % 2 == 1) continue;
            while (aSorting[i].first % 2 == 0)
            {
                aSorting[i].first /= 2;
                aSorting[i].second++;
            }
        }
        //sorting dengan kondisi. (cek baris 5-7 penjelasannya)
        //kenapa harus kunci/nilai pertama terbesar dahulu?
        //pembagian oleh 2 dari nilai terbesar akan menghasilkan nilai minimum.
        //contoh: himpunan A = {10, 10, 10, 20, 20}
        //kasus 1
        //========
        //cara 1: dipilih angka 20 (semua angka 20 dibagi 2), maka A = {10, 10, 10, 10, 10}. Total cara = 1.
        //cara 2: dipilih angka 10 (semua angka 10 dibagi 2), maka A = {5, 5, 5, 5, 5}. Total cara = 2.
        //program terminate karena anggota himpunan sudah ganjil semua, total cara = 2.
        //
        //kasus 2
        //========
        //cara 1: dipilih angka 10 (semua angka 10 dibagi 2), maka A = {5, 5, 5, 20, 20}. Total cara = 1.
        //cara 2: dipilih angka 20 (semua angka 20 dibagi 2), maka A = {5, 5, 5, 10, 10}. Total cara = 2.
        //cara 3: dipilih angka 10 (semua angka 10 dibagi 2), maka A = {5, 5, 5, 5, 5}. Total cara = 3.
        //
        //Terlihat kan mana yang minimum dari kasus-kasus di atas? Ternyata yang dibagi 2 dari yang terbesar
        //akan menghasilkan total cara minimum.
        sort(aSorting.begin(), aSorting.end(), besarDulu);
        count += aSorting[0].second;
        
        for (int i = 0; i < aSorting.size(); i++)
        {
            cout << "{" << aSorting[i].first << ", " << aSorting[i].second << "}\n";
        }

        for (int i = 0; i < aSorting.size()-1; i++)
        {
            if (aSorting[i].first != aSorting[i+1].first)
            {
                count += aSorting[i+1].second;
            }
        }
        cout << "Total cara: " << count << '\n';
    }
    return 0;
}
/*
45-21
24-12-6-3
16-8-4-2-1
*/