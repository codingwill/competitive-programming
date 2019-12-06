#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int min = 0;
    int max = 255;
    int ordo = 7;
    int ordoFilter = 3;
    int selFilter = ordoFilter * ordoFilter;
    int filterIndex = 1;
    int filterBaris = 1;
    int filterKolom = 1;
    int base[ordo][ordo];
    int finalMean[ordo][ordo];
    int finalMed[ordo][ordo];
    int filter[ordoFilter][ordoFilter];
    int sorting[selFilter];
    int barisAwal = 0, kolomAwal = 0;
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            /*
            if (i == 0 || j == 0 || i == ordo-1 || j == ordo-1)
            {
                base[i][j] = 0;
                finalMean[i][j] = base[i][j];
                finalMed[i][j] = base[i][j];
                continue;
            }
            */
            base[i][j] = (int)(rand() % max + min); 
            finalMean[i][j] = base[i][j];
            finalMed[i][j] = base[i][j];
        }
    }
    cout << "Sebelum difilter: " << endl;
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            cout << base[i][j] << "\t"; 
        }
        cout << endl;
    }
    cout << endl;
    
    
    while (filterIndex <= (ordo-2)*(ordo-2))
    {
        double average;
        int median;
        int jumlah = 0;
        int baris = 0, kolom = 0;
        for (int i = barisAwal ; baris < ordoFilter && i < ordo; i++)
        {
            kolom = 0;
            for (int j = kolomAwal; kolom < ordoFilter && j < ordo; j++)
            {
                filter[baris][kolom] = base[i][j];
                sorting[baris*ordoFilter + kolom] = base[i][j];
                jumlah += filter[baris][kolom];
                kolom++;
            }
            baris++;
            //System.out.println();
        }
        sort(sorting, sorting+9);
        median = sorting[selFilter/2];
        average = (double)(jumlah - filter[1][1])/8;
        filter[1][1] = (int)round(average); 
        finalMean[barisAwal+1][kolomAwal+1] = filter[1][1];
        filter[1][1] = median; 
        finalMed[barisAwal+1][kolomAwal+1] = filter[1][1];

        if (kolomAwal < ordo-2-1)
        {
            kolomAwal++;
        }
        else
        {
            kolomAwal = 0;
            if (barisAwal < ordo-2-1)
            {
                barisAwal++;
            }
        }
        filterIndex++;
    }
    cout << "Setelah difilter (mean): " << endl;
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            cout << finalMean[i][j] << "\t"; 
        }
        cout << endl;
    } 

    cout << "\nSetelah difilter (median): " << endl;
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            cout << finalMed[i][j] << "\t"; 
        }
        cout << endl;
    } 
}