import java.util.*;

public class kriptografi_spiral
{
    static Scanner input;
    static int ordo;
    static int sisaKosong;
    static char spiral[][];
    static boolean sudahIsi[][];
    static char arr[];
    static int ujungBaris;
    static int ujungKolom;
    static int awalBaris;
    static int awalKolom;
    static int x, y;
    static int plainIndex;
    static int sisaSel;
    static String simbol = "$";
    static String encrypt(String target)
    {
        String hasil = new String("");
        spiral = new char[ordo][ordo];
        ujungBaris = ordo-1; //X -> baris
        ujungKolom = ordo-1; //Y -> kolom
        awalBaris = 0;
        awalKolom = 0;
        x = 0;
        y = 0;
        plainIndex = 0;

        for (int i = 0; i < sisaKosong; i++)
        {
            target += simbol;
        }
        //System.out.println(sisaKosong);
        for (int i = 0; i < Math.ceil((float)ordo/2); i++)
        //abcdefghijklmnopq
        {
            //genap atau kolom
            for (int j = awalKolom; j <= ujungKolom; j++)
            {
                spiral[awalBaris][j] = target.charAt(plainIndex);
                plainIndex++; //1
            }
            awalBaris++;

            for (int j = awalBaris; j <= ujungBaris; j++)
            {
                spiral[j][ujungKolom] = target.charAt(plainIndex);
                plainIndex++;
            }
            ujungKolom--;

            if (awalKolom <= ujungKolom)
            {
                for (int j = ujungKolom; j >= awalKolom; j--)
                {
                    spiral[ujungBaris][j] = target.charAt(plainIndex);
                    plainIndex++;
                }
            }
            ujungBaris--;

            if (awalBaris <= ujungBaris)
            {
                for (int j = ujungBaris; j >= awalBaris; j--)
                {
                    spiral[j][awalKolom] = target.charAt(plainIndex);
                    plainIndex++;
                }
            }
            awalKolom++;
        }

        for (int i = 0; i*i < target.length(); i++)
        {
            for (int j = 0; j*j < target.length(); j++)
            {
                hasil += spiral[j][i];
            }
        }
        for (int i = 0; i*i < target.length(); i++)
        {
            for (int j = 0; j*j < target.length(); j++)
            {
                System.out.print(spiral[i][j] + " ");
            }
            System.out.println();
        }
        return hasil;
    }

    static String decrypt(String target)
    {
        String hasil = new String("");
        spiral = new char[ordo][ordo];
        sudahIsi= new boolean[ordo][ordo];
        arr = new char[5];
        ujungBaris = ordo-1;
        ujungKolom = ordo-1;
        awalBaris = 0;
        awalKolom = 0;
        x = 0;
        y = 0;
        plainIndex = 0;

        for (int i = 0; i*i < target.length(); i++)
        {
            for (int j = 0; j*j < target.length(); j++)
            {
                spiral[j][i] = target.charAt(plainIndex);
                plainIndex++;
            }
        }
        for (int i = 0; i < Math.ceil((float)ordo/2); i++)
        //abcdefghijklmnopq
        {
            //genap atau kolom
            for (int j = awalKolom; j <= ujungKolom; j++)
            {
                hasil += spiral[awalBaris][j];
            }
            awalBaris++;

            for (int j = awalBaris; j <= ujungBaris; j++)
            {
                hasil += spiral[j][ujungKolom];
            }
            ujungKolom--;

            if (awalKolom <= ujungKolom)
            {
                for (int j = ujungKolom; j >= awalKolom; j--)
                {
                    hasil += spiral[ujungBaris][j];
                }
            }
            ujungBaris--;

            if (awalBaris <= ujungBaris)
            {
                for (int j = ujungBaris; j >= awalBaris; j--)
                {
                    hasil += spiral[j][awalKolom];
                    plainIndex++;
                }
            }
            awalKolom++;
        }
        return hasil.replace(simbol, "");
    }

    boolean status = false;
    public static void main(String args[])
    {
        input = new Scanner(System.in);
        System.out.print("Masukkan plain text: ");
        String plain = input.nextLine();
        String cipher = new String();
        ordo = (int)(Math.ceil(Math.sqrt((double)plain.length())));
        sisaKosong = (ordo*ordo) - plain.length();
        //System.out.println(ordo);
        System.out.println("Hasil enkripsi: " + encrypt(plain));
        cipher = cekCipher("Masukkan cipher text: ");
        ordo = (int) Math.sqrt(cipher.length());
        System.out.println("Hasil dekripsi: " + decrypt(cipher));
    }

    static String cekCipher(String pertanyaan)
		{
            boolean invalid = true;
			String temp = new String("");
			while (invalid)
			{
                invalid = false;
                System.out.print(pertanyaan);
				temp = input.nextLine();
                if (Math.sqrt(temp.length()) - (int)Math.sqrt(temp.length()) > 1e-6)
                {
                    invalid = true;
                }
				if (invalid) System.out.println("Input yang Anda masukkan BUKAN Spiral Cipher Text!");
			}
			return temp;
		}
}
/*
asdfghjkl
asd
klf
jhg
asdklfjhg
i o i
o i o
i o i

for (int i = 0; i*i < target.length(); i++)
{
    for (int j = 0; j*j < target.length(); j++)
    {
        System.out.print(spiral[i][j] + " ");
    }
    System.out.println();
}

for (int i = 0; i*i < spiral.length; i++)
{
    for (int j = 0; j*j < spiral.length; j++)
    {
        System.out.print(spiral[i][j]);
    }
    System.out.println();
}
*/