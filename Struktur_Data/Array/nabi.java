import java.util.Scanner;

/*
** Willy Indrayana Komara (M3119086)
*/
public class nabi {
    public static void main(String[] args)
    {
        //membuat array nama-nama nabi
        String[] nabi = new String[5];

        //membuat Scanner
        Scanner scan = new Scanner(System.in);

        //mengisi data di dalam array
        for (int i = 0; i < nabi.length; ++i)
        {
            System.out.println("Masukkan nama nabi yang Anda ketahui: " + i + ": ");
            nabi[i] = scan.nextLine();
        }

        System.out.println("------------");

        //menampilkan isi array
        for (String n : nabi)
        {
            System.out.println(n);
        }
    }
}