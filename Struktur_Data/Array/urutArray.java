import java.util.Arrays;
import java.util.Scanner;

/*
** Willy Indrayana Komara (M3119086)
*/
public class urutArray {
    public static void main(String[] args)
    {
        //membuat array
        int nomer[] = {70, 20, 35, 10, 25, 60};

        //menampilkan elemen array sebelum diurutkan
        System.out.println("***** Sebelum diurutkan *****");
        for (int x : nomer)
        {
            System.out.println(x + " ");
        }

        //melakukan pengurutan
        Arrays.sort(nomer);
        //menampilkan elemen array setelah diurutkan
        System.out.println("***** Setelah diurutkan *****");
        for (int x : nomer)
        {
            System.out.println(x + " ");
        }
    }
}