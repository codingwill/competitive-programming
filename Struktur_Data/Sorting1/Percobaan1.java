import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/

class InsertionDemo
{
    public static void insertionSort(int[] arr)
    {
        //iterasi setiap elemen kecuali elemen pertama (ke-0)
        for (int i = 1; i < arr.length; ++i)
        {
            //key sebagai variabel sementara untuk menampung elemen index ke-i
            //yang kemudian dibandingkan dengan elemen index ke-(i-1)
            int key = arr[i];
            int j = i - 1;
            //selama nilai elemen index ke-j lebih besar dari key
            //dan indexnya tidak melebihi batas array minimal
            //maka nilai index ke-j akan diswap dengan index ke-(j+1)
            //alias nilai yang lebih besar akan digeser ke kanan
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
    
    public static void tampil(int data[])
    {
        //perulangan basic untuk menampilkan seluruh elemen pada array
        for (int i = 0; i < data.length; ++i)
        {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }
}

public class Percobaan1 
{
    public static void main(String[] args)
    {
        int a[] = {10, 6, 8, 3, 1};
        InsertionDemo.tampil(a);
        InsertionDemo.insertionSort(a);
        InsertionDemo.tampil(a);
    }
}