/*
** Willy Indrayana Komara (M3119086)
*/
public class ContohArray
{
    public static void main(String[] args)
    {
        //array declaration
        int[] contohArray;

        //memory allocation
        contohArray = new int[6];

        //first index array initialization
        contohArray[0] = 10;

        //second index array initialization
        contohArray[1] = 20;

        //n-index array initialization
        contohArray[2] = 30;
        contohArray[3] = 40;
        contohArray[4] = 50;
        contohArray[5] = 60;
        
        //print array
        for (int i = 0; i < contohArray.length; ++i)
        {
            System.out.println("Elemen array indeks ke-" + i + ": " + contohArray[i]);
        }
    }
}