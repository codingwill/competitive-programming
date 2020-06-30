import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/

public class latihan1 
{
    public static void main(String[] args)
    {
        //perulangan sebanyak 2x
        for (int i = 0; i < 2; ++i)
        {
            Scanner input = new Scanner(System.in);
            System.out.print("Masukkan kalimat: ");
            String kalimat = input.nextLine();
            isPalindrome(kalimat);
            System.out.println();
        }
    }    

    //fungsi untuk mengecek palindrom dan mencetak 
    //string secara balik/reversed
    static void isPalindrome(String a)
    {
        //stack untuk menampung tiap char pada kalimat
        Stack<Character> s = new Stack<Character>();

        //push char pada stack
        for (int i = 0; i < a.length(); ++i)
        {
            s.push(a.charAt(i));
        }
        System.out.print("Hasil = ");

        //untuk menampung kalimat hasil reverse(a)
        String b = "";
        
        //kalimat hasil reversed merupakan hasil gabungan
        //characters dari tumpukan teratas hingga terbawah
        while (!s.isEmpty())
        {
            System.out.print(s.peek());
            b += s.pop();
        }

        //mengecek syarat palindrome a == reversed(a)
        //dengan kata lain a == b
        if (a.equals(b)) System.out.println("\nPalindrom");
        else System.out.println("\nBukan Palindrom");
    }
}