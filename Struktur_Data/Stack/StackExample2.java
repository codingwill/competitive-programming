import java.util.*;
/*
** Willy Indrayana Komara (M3119086)
*/
public class StackExample2 
{
    public static void main(String[] args)
    {
        Stack<String> sk = new Stack<String>();

        sk.push("a");
        sk.push("c");
        sk.push("e");
        sk.push("d");
        //urutan stack sementara (atas ke bawah)
        //{d, e, c, a}
        
        //iterator yang diinisialisasi sbg pointer yang menunjuk value pada stack
        Iterator it = sk.iterator();

        //print size/ukuran/banyak elemen pada stack
        System.out.println("Size before pop(): " + sk.size());

        //perulangan dengan menggunakan iterator start di paling atas elemen pertama (null), 
        //selama terdapat elemen pada stack di bawahnya maka akan terus berulang
        while(it.hasNext())
        {
            // iValue adalah elemen yang nilainya meruapakan iterator/pointer yang
            // menunjuk elemen di bawahnya, kemudian dicetak.
            String iValue = (String) it.next();
            System.out.println("Iterator value: " + iValue);
        }

        //elemen teratas dicopy ke objek value kemudian dipop(hapus).
        String value = (String) sk.pop();

        //cetak objek value yang merupakan elemen teratas pada stack sk
        //walaupun stack sk teratas sudah dihapus
        System.out.println("value : " + value);
    }    
}
