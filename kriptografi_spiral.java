import java.util.*;

public class kriptografi_spiral
{
    static Scanner input = new Scanner(System.in);
    public static void main(String args[])
    {
        String plain = input.nextLine();
        int ordo = (int)Math.ceil(Math.sqrt((double)plain.length()));
        int sisaX = (ordo*ordo) % plain.length();
        //System.out.println(ordo);
        for (int i = 0; i < sisaX; i++)
        {
            plain += "x";
        }
        char spiral[][] = new char[ordo][ordo];
        boolean sudahIsi[][] = new boolean[ordo][ordo];
        char arr[] = new char[5];

        System.out.println(arr[0]);

        int ujungX = ordo-1;
        int ujungY = ordo-1;
        int awalX = 0;
        int awalY = 1;
        int x = 0, y = 0;
        int plainIndex = 0;
        for (int i = 0; i < ordo*2-1; i++)
        {
            if (i % 2 == 0)
            {
                //genap atau kolom
                while (y <= ujungX)
                {
                    spiral[y][x] = plain.charAt(plainIndex);
                    plainIndex++; //1
                    y++; //1
                }
                ujungX = ;
            }
            else
            {
                //ganjil
            }
        }
        
        System.out.println(sudahIsi[0][0]);
    }
}