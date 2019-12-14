import java.util.*;
/*
Code by wkwkwill (Willy I. K.)
github.com/wkwkwill
*/
public class java_fungsi_geometri
{
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        double a, b, c;
        a = input.nextDouble(); //suku pertama
        b = input.nextDouble(); //rasio
        c = input.nextDouble(); //suku terakhir
        System.out.println(geometri(a, b, c)); //fungsi return biasa tanpa rekursi (menggunakan formula math)
        System.out.println(geometriRekursif(a, b, c)); //fungsi return dengan rekursi
    }

    //non-rekursif
    static double geometri(double a, double r, double n)
    {
        if (r > 1)
            return a*(Math.pow(r, n) - 1)/(r-1);
        else if (r < 1)
            return a*(1 - Math.pow(r, n))/(1-r);
        return a*n;
    }
    
    //rekursif
    static double geometriRekursif(double a, double r, double n)
    {
        if (n == 0)
            return 0;
        return a + geometriRekursif(a*r, r, n-1);
    }
}
// 2 4 8 16 32 64 128 = 254