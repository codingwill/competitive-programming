#include <bits/stdc++.h>

using namespace std;

struct Cpu
{
    int angkatJari;
    int sisaTangan = 2;
    int tebakan;
};

int main()
{
    srand(time(NULL));
    int player;
    Cpu cpu[3];
    int sumJariAngkat = 0;
    int sisaTangan = 2;
    int tebakan, angkatJari;
    int turn = 3;
    int sumTangan;
    int cpuSisaTangan = 6;
    while (sisaTangan && cpuSisaTangan)
    {
        if (cpu[turn].sisaTangan == 0)
        {
            continue;
        }
        cout << "======================" << endl;
        if (turn != 3) cout << "Giliran  CPU[" << turn << "] untuk menebak!" << endl;
        else cout << "Giliran Anda untuk menebak!" << endl;
        sumJariAngkat = 0;
        cout << "======================" << endl;
        cout << "Jumlah jari yang mau diangkat: ";
        cin >> angkatJari;
        sumJariAngkat += angkatJari;
        for (int i = 0; i < 3; i++)
        {
            if (cpu[i].sisaTangan == 0)
            {
                continue;
            }
            cpu[i].angkatJari = rand() % (cpu[i].sisaTangan + 1);
            sumJariAngkat += cpu[i].angkatJari;
        }
        if (turn == 3)
        {
            cout << "Masukkan tebakan: ";
            cin >> tebakan;
            if (sumJariAngkat == tebakan)
            {
                cout << "Tebakan benar!" << endl;
                sisaTangan--;
                cout << "Sisa tangan = " << sisaTangan << endl;
            }
            else
            {
                cout << "Tebakan salah!" << endl;
                cout << "Sisa tangan = " << sisaTangan << endl;
            }
        }
        else
        {
            cpu[turn].tebakan = rand() % (sumTangan + 1);
            cout << "Tebakan CPU[" << turn << "] adalah " << cpu[turn].tebakan << endl;
            if (sumJariAngkat == cpu[turn].tebakan)
            {
                cout << "Tebakan CPU[" << turn << "] benar!" << endl;
                cpu[turn].sisaTangan--;
                //cout << "Sisa tangan = " << sisaTangan << endl;
            }
            else
            {
                cout << "Tebakan CPU[" << turn << "] salah!" << endl;
                //cout << "Sisa tangan = " << sisaTangan << endl;
            }
        }       
        //cout << sumJariAngkat << endl;
        cout << "Jumlah jari yang diangkat adalah " << sumJariAngkat << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Sisa tangan CPU[" << i << "] adalah " << cpu[i].sisaTangan << endl;
        }
        cout << "Sisa tangan Anda adalah " << sisaTangan << endl;
        turn = (turn + 1) % 4;
        cpuSisaTangan = cpu[0].sisaTangan + cpu[1].sisaTangan + cpu[2].sisaTangan;
        sumTangan = sisaTangan + cpuSisaTangan;
        cout << "\nTekan Enter untuk lanjut...";
        cin.ignore();
        if (cin.get() == '\n') system("CLS");
        else system("CLS");
    }
    cout << "=====================" << endl;
    if (sisaTangan == 0) cout << "Selamat Anda menang!" << endl;
    else cout << "Maaf, Anda kalah!" << endl;
}