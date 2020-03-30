import java.util.*;
/* WILLY I KOMARA - M3119086 */
class Player
{
    //Instance Variable
    int pos_x, pos_y;

    //Constructor
    public Player(int x, int y)
    {
        pos_x = x;
        pos_y = y;
    }
}

public class MainMethod
{
    public static void main(String args[])
    {
        Player aku = new Player(1, 2); //membuat objek aku dari class Player sekaligus 
                                       //mengkonstruksi dan menginisialisasi variabel pos_x dan pos_y dari objek aku
        Player kamu = new Player(11, 22); //membuat objek kamu dari class Player sekaligus 
                                          //mengkonstruksi dan menginisialisasi variabel pos_x dan pos_y dari objek kamu
        System.out.println("aku pos_x = " + aku.pos_x + "\naku pos_y = " + aku.pos_y);
        System.out.print("kamu pos_x = " + kamu.pos_x + "\nkamu pos_y = " + kamu.pos_y);
    }
}