import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/
public class latihan {
    public static void main(String[] args)
    {
        int arr[] = {21, 6, 18, 29, 7, 10, 14, 11};
        urut(arr);
        System.out.println("Rataan: " + hitungRataan(arr));
        System.out.println("Min: " + hitungMin(arr));
        System.out.println("Max: " + hitungMax(arr));
        printGanjil(arr);
        printPrima(arr);
    }

    static void urut(int a[])
    {
        Arrays.sort(a);
    }

    static double hitungRataan(int a[])
    {
        double sum = 0;
        for (int i = 0; i < a.length; ++i)
        {
            sum += a[i];
        }
        return sum / a.length;
    }

    static int hitungMin(int a[])
    {
        return a[0];
    }

    static int hitungMax(int a[])
    {
        return a[a.length-1];
    }

    static void printGanjil(int a[])
    {
        System.out.print("Data ganjil: { ");
        for (int i : a)
        {
            if (i % 2 == 1)
            {
                System.out.print(i + " ");
            }
        }
        System.out.println("}");
    }
    
    static void printPrima(int a[])
    {
        System.out.print("Data prima: { ");
        for (int i : a)
        {
            int divisor = 0;
            for (int j = 2; j * j < i; ++j)
            {
                if (i % j == 0) ++divisor;
            }
            if (divisor > 0) continue;
            System.out.print(i + " ");
        }
        System.out.println("}");
    }
    
}