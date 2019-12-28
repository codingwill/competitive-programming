import java.util.*;

public class kriptografi_spiral
{
    static Scanner input;
    static String plain;
    static String cipher;
    static int ordo;
    static int sisaX;
    static char spiral[][];
    static boolean sudahIsi[][];
    static char arr[];
    static int ujungX;
    static int ujungY;
    static int awalX;
    static int awalY;
    static int x, y;
    static int plainIndex;
    static int sisaSel;
    static void encrypt()
    {
        spiral = new char[ordo][ordo];
        sudahIsi= new boolean[ordo][ordo];
        arr = new char[5];

        //System.out.println(arr[0]);
        ujungX = ordo-1;
        ujungY = ordo-1;
        awalX = 0;
        awalY = 0;
        x = 0;
        y = 0;
        plainIndex = 0;
        sisaSel = (int) Math.sqrt(Math.ceil(Math.sqrt(plain.length()))) - plain.length(); //untuk nyimpen huruf X atau sisa sel yang kosong

        for (int i = 0; i < sisaX; i++)
        {
            plain += "$";
        }

        for (int i = 0; i < Math.ceil((float)ordo/2); i++)
        //abcdefghijklmnopq
        {
            //genap atau kolom
            for (int j = awalY; j <= ujungY; j++)
            {
                spiral[awalX][j] = plain.charAt(plainIndex);
                plainIndex++; //1
            }
            awalX++;

            for (int j = awalX; j <= ujungX; j++)
            {
                spiral[j][ujungY] = plain.charAt(plainIndex);
                plainIndex++;
            }
            ujungY--;

            if (awalY <= ujungY)
            {
                for (int j = ujungY; j >= awalY; j--)
                {
                    spiral[ujungX][j] = plain.charAt(plainIndex);
                    plainIndex++;
                }
            }
            ujungX--;

            if (awalX <= ujungX)
            {
                for (int j = ujungX; j >= awalX; j--)
                {
                    spiral[j][awalY] = plain.charAt(plainIndex);
                    plainIndex++;
                }
            }
            awalY++;
        }

        for (int i = 0; i*i < plain.length(); i++)
        {
            for (int j = 0; j*j < plain.length(); j++)
            {
                cipher += spiral[j][i];
            }
            //System.out.println();
        }
        System.out.print("Hasil encrypt: ");
        System.out.println(cipher);
        for (int i = 0; i*i < plain.length(); i++)
        {
            for (int j = 0; j*j < plain.length(); j++)
            {
                System.out.print(spiral[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void decrypt()
    {
        cipher = "";
        spiral = new char[ordo][ordo];
        sudahIsi= new boolean[ordo][ordo];
        arr = new char[5];

        //System.out.println(arr[0]);
        ujungX = ordo-1;
        ujungY = ordo-1;
        awalX = 0;
        awalY = 0;
        x = 0;
        y = 0;
        plainIndex = 0;
        
        for (int i = 0; i*i < cipher.length(); i++)
        {
            for (int j = 0; j*j < cipher.length(); j++)
            {
                spiral[j][i] = cipher.charAt(plainIndex);
                plainIndex++;
            }
            //System.out.println();
        }
        //System.out.println("Ordo = " + ordo);
        for (int i = 0; i < Math.ceil((float)ordo/2); i++)
        //abcdefghijklmnopq
        {
            //genap atau kolom
            for (int j = awalY; j <= ujungY; j++)
            {
                plain += spiral[awalX][j];
            }
            awalX++;

            for (int j = awalX; j <= ujungX; j++)
            {
                plain += spiral[j][ujungY];
            }
            ujungY--;

            if (awalY <= ujungY)
            {
                for (int j = ujungY; j >= awalY; j--)
                {
                    plain += spiral[ujungX][j];
                }
            }
            ujungX--;

            if (awalX <= ujungX)
            {
                for (int j = ujungX; j >= awalX; j--)
                {
                    plain += spiral[j][awalY];
                    plainIndex++;
                }
            }
            awalY++;
        }
        plain = plain.replace("$", "");
        
        System.out.print("Hasil decrypt: ");
        System.out.println(plain);
        for (int i = 0; i*i < spiral.length; i++)
        {
            for (int j = 0; j*j < spiral.length; j++)
            {
                System.out.print(spiral[i][j]);
            }
            System.out.println();
        }

    }
    boolean status = false;
    public static void main(String args[])
    {
        input = new Scanner(System.in);
        System.out.print("Masukkan plain text: ");
        plain = input.nextLine();
        cipher = new String();
        ordo = (int)Math.ceil(Math.sqrt((double)plain.length()));
        sisaX = (ordo*ordo) % plain.length();
        //System.out.println(ordo);
        encrypt();
        System.out.print("Masukkan cipher text: ");
        cipher = input.nextLine();
        ordo = (int) Math.sqrt(cipher.length());
        decrypt();
        //System.out.println(spiral[0][0]);
        //System.out.println();
        //System.out.println(spiral[1][0]);
    }
}
/*
asdfghjkl
asd
klf
jhg
asdklfjhg
*/