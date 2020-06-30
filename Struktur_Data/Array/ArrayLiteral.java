/*
** Willy Indrayana Komara (M3119086)
*/
public class ArrayLiteral {
    public static void main(String[] args)
    {
        String[] namaNabi = {"Nuh", "Ibrahim", "Musa", "Isa", "Muhammad"};

        for (int i = 0; i < namaNabi.length; ++i)
        {
            System.out.println("indeks ke-" + i + ": " + namaNabi[i]);
        }
    }
}